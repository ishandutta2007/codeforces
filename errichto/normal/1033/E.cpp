#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

int query(vector<int> w) {
	printf("? %d\n", (int) w.size());
	for(int x : w) {
		printf("%d ", x);
	}
	puts("");
	fflush(stdout);
	//~ return w.size() * (w.size() - 1) / 2;
	int r;
	scanf("%d", &r);
	return r;
}

bool yes(int a, vector<int> w) {
	//~ assert(!secik.count(a));
	for(int zz : w) {
		assert(a != zz);
	}
	int x = query(w);
	w.push_back(a);
	int y = query(w);
	assert(y >= x);
	return y > x;
}

int index(int a, vector<int> w) {
	if(w.empty() || !yes(a, w)) {
		return -1;
	}
	int low = 0, high = (int) w.size() - 1;
	while(low < high) {
		int mid = (low + high) / 2;
		vector<int> small;
		for(int i = 0; i <= mid; ++i) {
			small.push_back(w[i]);
		}
		if(yes(a, small)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

const int nax = 605;
bool vis[nax], vis2[nax];
int kol[nax];
int n;
vector<int> edges[nax];

void add_edge(int a, int b) {
	debug() << imie(a) imie(b);
	assert(a != b);
	edges[a].push_back(b);
	edges[b].push_back(a);
}

void dfs_path(int a, int goal, vector<int>& vec) {
	vec.push_back(a);
	if(a == goal) {
		printf("N %d\n", (int) vec.size());
		for(int x : vec) printf("%d ", x);
		puts("");
		exit(0);
	}
	assert(!vis2[a]);
	vis2[a] = true;
	for(int b : edges[a]) {
		if(vis[b] && !vis2[b]) {
			dfs_path(b, goal, vec);
		}
	}
}

void dfs(int a) {
	assert(!vis[a]);
	vis[a] = true;
	vector<int> gather;
	for(int i = 1; i <= n; ++i) {
		if(vis[i] && kol[i] == kol[a] && i != a) {
			gather.push_back(i);
		}
	}
	int which = index(a, gather);
	if(which != -1) {
		vector<int> vec;
		dfs_path(a, gather[which], vec);
		//~ add_edge(a, gather[which]);
		//~ dfs_cycle(a);
		assert(false);
	}
	while(true) {
		gather.clear();
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				gather.push_back(i);
			}
		}
		which = index(a, gather);
		if(which != -1) {
			int b = gather[which];
			add_edge(a, b);
			kol[b] = kol[a] ^ 1;
			dfs(b);
		}
		else {
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			kol[i] = 0;
			dfs(i);
		}
	}
	set<int> secik;
	for(int i = 1; i <= n; ++i) {
		if(kol[i]) {
			secik.insert(i);
		}
	}
	printf("Y %d\n", (int) secik.size());
	for(int x : secik) printf("%d ", x);
	puts("");
}