#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

// MODINT
template<int MOD> struct ModInt {
	ll x;
	ModInt(ll n=0) { n %= MOD; if (n < 0) n += MOD; x = n; }
	int get() const { return (int) x; }
	ModInt operator + (const ModInt& other) { return ModInt(x + other.x); }
	ModInt operator - (const ModInt& other) { return ModInt(x + MOD - other.x); }
	ModInt operator * (const ModInt& other) { return ModInt(x * other.x); } 
	ModInt& operator += (const ModInt& other) { x = (x + other.x) % MOD; return *this; }
	ModInt& operator -= (const ModInt& other) { x = (x + MOD - other.x) % MOD; return *this; }
	ModInt& operator *= (const ModInt& other) { x = (x * other.x) % MOD; return *this; }
};

struct Guy {
	int id;
	int pos, stime;
	Guy(int i, int p, int t) {
		pos = p;
		stime = t;
		id = i;
	}
	bool operator < (const Guy& other) const {
		if (stime == other.stime) return pos < other.pos;
		else return stime < other.stime;
	}
};
struct VGuy {
	int id;
	int pos, stime;
	VGuy(int i, int p, int t) {
		pos = p;
		stime = t;
		id = i;
	}
	bool operator < (const VGuy& other) const {
		if (pos == other.pos) return stime < other.stime;
		else return pos < other.pos;
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int group, pos, stime;
	int n, width, height;
	cin >> n >> width >> height;
	deque<int> groupid[n+1];
	pair<int,int> ans[n+1];
	vector<VGuy> vert;
	vector<Guy> horiz;
	for (int i = 1; i <= n; i++) {
		cin >> group >> pos >> stime;
		if (group == 1) {
			vert.push_back(VGuy(i, pos, pos-stime));
		}
		else {
			horiz.push_back(Guy(i, pos, pos-stime));
		}
	}
	sort(horiz.begin(), horiz.end());
	sort(vert.begin(), vert.end());
	// store ids
	map<int,int> timemap; // maps time to position
	int curr;
	for (int i = 0; i < horiz.size(); i++) {
		if (i == 0 || horiz[i].stime != horiz[i-1].stime) {
			timemap.insert(pair<int,int>(horiz[i].stime, i));
			curr = i; 
		}
		groupid[curr].push_front(horiz[i].id);
	}
	// do the thing
	for (VGuy next: vert) {
		if (timemap.count(next.stime)) {
			int index = timemap[next.stime];
			ans[groupid[index].front()] = pair<int,int>(next.pos, height);
			//cerr << groupid[index].front() << " is now done at " << next.pos << nl;
			groupid[index].pop_front();
			groupid[index].push_back(next.id);
			//cerr << next.id << " pushed to back of group " << index << nl;
		}
		else {
			//cerr << next.id << " missed at " << next.pos << nl;
			ans[next.id] = pair<int,int>(next.pos, height);
		}
	}
	// get ends
	for (int i = 0; i < horiz.size(); i++) {
		for (int j = 0; !groupid[i].empty(); j++) {
			ans[groupid[i].back()] = pair<int,int>(width, horiz[i+j].pos);
			groupid[i].pop_back();
		}
	}
	// output
	for (int i = 1; i <= n; i++) {
		cout << ans[i].first << " " << ans[i].second << nl;
	}

	return 0;
}