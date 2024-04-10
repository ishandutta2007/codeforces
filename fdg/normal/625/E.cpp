#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int p[100005], a[100005], moment[100005];

struct frog {
	int p, a, id;
};

bool operator < (const frog &a, const frog &b) {
	return a.p < b.p;
}

struct event {
	int id1, id2, tm;
};

bool operator < (const event &a, const event &b) {
	return a.tm > b.tm || a.tm == b.tm && a.id1 > b.id1;
}

int catchTime(int id1, int p1, int a1, int id2, int p2, int a2, int curTime) {
	// Special case: catch in one move.
	{
		long long pos1 = p1 + a1;
		long long pos2 = p2;
		if (p2 < p1) pos2 += m;
		pos2 += a2 * (1 - (id2 > id1));
		
		if (pos1 >= pos2)
			return 1 + curTime;
	}
	int l = 0, r = 1e+9 + 9;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		
		long long pos1 = p1 + 1LL * a1 * mid;
		long long pos2 = p2;
		if (p2 < p1) pos2 += m;
		pos2 += 1LL * a2 * (mid - (id2 > id1));
		
		if (pos1 >= pos2) r = mid;
		else l = mid;
	}
	
	return r > 1e+9 + 7 ? -1 : (curTime + r); 
}

int getPos(int id, int toTm) {
	return (p[id] + 1LL * (toTm - moment[id]) * a[id]) % m;
}

void move(int id, int toTm) {
	if (moment[id] > toTm) return;
	
	// cout << "Move:	" << id << "	" << moment[id] << "	" << toTm << endl;
	
	p[id] = (p[id] + 1LL * (toTm - moment[id]) * a[id]) % m;
	moment[id] = toTm;
}

int catchTime(int id1, int id2) {
	// move(id1, moment[id2]);
	// move(id2, moment[id1]);
	
	int mxTm = max(moment[id1], moment[id2]);
	
	int tm = catchTime(id1, getPos(id1, mxTm), a[id1], id2, getPos(id2, mxTm), a[id2], mxTm);
	// cout << "Catch time:	" << id1 << " " << p[id1] << " " << a[id1] << " - "
	// 	 << id2 << " " << p[id2] << " " << a[id2] << " - " << tm << endl;
	return tm;
}

bool out[100005];

set<pair<int, int>> f;
set<pair<int, int>>::iterator where[100005];

void stupid() {
	for (int it = 0; it < 2 * m; ++it) {
		for (int i = 0; i < n; ++i) {
			if (out[i]) continue;
			int eaten = 0;
			for (int j = 0; j < a[i]; ++j) {
				p[i] = (p[i] + 1) % m;
				for (int t = 0; t < n; ++t) {
					if (t != i && !out[t] && p[t] == p[i]) {
						cout << "Eaten:	" << i << "	" << t << "	" << it + 1 << endl;
						++eaten;
						out[t] = true;
					}
				}
			}
			a[i] -= eaten;
		}	
	}
	
	int left = 0;
	for (int i = 0; i < n; ++i) {
		if (!out[i]) ++left;
	}
	printf("%d\n", left);
	for (int i = 0; i < n; ++i) {
		if (!out[i]) printf("%d ", i + 1);
	}
	exit(0);
}

int main() {
	scanf("%d%d", &n, &m);
	vector<frog> frogs;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i], &a[i]); --p[i];
		frogs.push_back(frog{p[i], a[i], i});
	}
	sort(frogs.begin(), frogs.end());
	
	// stupid();
	
	priority_queue<event> q;
	for (int i = 0; i < n; ++i) {
		int ni = (i + 1) % n;
		
		int tm = catchTime(frogs[i].id, frogs[i].p, frogs[i].a, frogs[ni].id, frogs[ni].p, frogs[ni].a, 0);
		// cout << "(" << frogs[i].id << "	" << frogs[i].p << "	" << frogs[i].a
		// 		<< ") -> (" << frogs[ni].id << "	" << frogs[ni].p << "	"
		// 		<< frogs[ni].a << ") = " << tm << endl;
		if (tm != -1)
			q.push(event{frogs[i].id, frogs[ni].id, tm});
	
		f.insert({i, frogs[i].id});
		where[frogs[i].id] = f.end();
		where[frogs[i].id]--;
	}
	
	int lastTm = -1;
	vector<pair<int, pair<int, int>>> toUpdate; 
	
	while (q.size() || toUpdate.size()) {
		if (q.size() == 0 || lastTm < q.top().tm) {
			for (auto p : toUpdate) {
				move(p.first, p.second.first);
				a[p.first] = max(0, a[p.first] - p.second.second);
			}
			
			for (auto p : toUpdate) {
				if (out[p.first]) continue;
				
				set<pair<int, int>>::iterator it = where[p.first], nx; ++it;
				if (it == f.end()) it = f.begin();
				if (p.first != it->second) {
					int newTm = catchTime(p.first, it->second);
					if (newTm != -1)
						q.push(event{p.first, it->second, newTm});
				}
					
				nx = where[p.first];
				if (nx == f.begin()) {
					nx = f.end();
				}
				--nx;
				
				if (nx->second != p.first) {
					int newTm = catchTime(nx->second, p.first);
					if (newTm != -1)
						q.push(event{nx->second, p.first, newTm});
				}
			}
			toUpdate.clear();
		}
		
		if (!q.size()) break;
		
		event cur = q.top(); q.pop();
		// cout << "Got:	" << cur.id1 << "	" << cur.id2 << "	" << cur.tm << endl;
		if (out[cur.id1] || out[cur.id2]) continue;
		
		int tm = catchTime(cur.id1, cur.id2);
		if (tm != cur.tm) {
			// cout << "Ignore:	" << tm << " != " << cur.tm << endl;
			continue;
		}
	
		set<pair<int, int>>::iterator it = where[cur.id2], nx;
		int eaten = 0;
		while (catchTime(cur.id1, it->second) == tm) {
			// cout << "Catch:	" << cur.id1 << "	" << it->second << "	" << cur.tm << endl;
			if (cur.id1 == it->second) break;
			
			out[it->second] = true;
			++eaten;
			
			nx = it; ++nx;
			if (nx == f.end()) nx = f.begin();
			
			f.erase(it); it = nx;
		}
		toUpdate.push_back({cur.id1, {tm, eaten}});
		lastTm = tm;
	}
	
	int left = 0;
	for (int i = 0; i < n; ++i) {
		if (!out[i]) ++left;
	}
	printf("%d\n", left);
	for (int i = 0; i < n; ++i) {
		if (!out[i]) printf("%d ", i + 1);
	}
	
	return 0;
}