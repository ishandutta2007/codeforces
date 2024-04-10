#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int nax = 1e5 + 5;
const int inf = 1e9 + 5;
vector<pair<int,int>> w[nax];
int subtree[nax];
long long answer;

const int pot = 128 * 1024;
int tr[2*pot];
int inv[nax], which_group[nax];

int get_min(int low, int high) {
	if(low > high) return inf;
	low += pot;
	high += pot;
	int r = min(tr[low], tr[high]);
	while(low < high - 1) {
		if(low % 2 == 0) r = min(r, tr[low+1]);
		if(high % 2) r = min(r, tr[high-1]);
		low /= 2;
		high /= 2;
	}
	return r;
}

int n;

void dfs(int a, int par) {
	subtree[a] = 1;
	for(pair<int,int> p : w[a]) {
		int b = p.first;
		if(b == par) continue;
		dfs(b, a);
		subtree[a] += subtree[b];
		debug() << imie(a) imie(b) imie(subtree[b]) imie(p.second);
		answer += (long long) p.second * min(subtree[b], n - subtree[b]);
	}
}

void dfs_gather(int a, int par, vector<int> & they) {
	they.push_back(a);
	for(pair<int,int> p : w[a])
		if(p.first != par)
			dfs_gather(p.first, a, they);
}

int main() {
	scanf("%d", &n);
	if(n == 1) {
		puts("0");
		puts("1");
		return 0;
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		w[a].push_back({b, c});
		w[b].push_back({a, c});
	}
	dfs(1, -1);
	
	int root = 1;
	while(true) {
		bool anything = false;
		for(pair<int,int> p : w[root]) {
			int b = p.first;
			if(subtree[b] < subtree[root] && 2 * subtree[b] >= n) {
				root = b;
				anything = true;
				break;
			}
		}
		if(!anything) break;
	}
	
	bool is_soft = true;
	for(pair<int,int> p : w[root])
		if(subtree[p.first] * 2 == n)
			is_soft = false;
	debug() << imie(is_soft);
	
	vector<vector<int>> groups;
	groups.push_back({root});
	for(pair<int,int> p : w[root]) {
		vector<int> they;
		dfs_gather(p.first, root, they);
		groups.push_back(they);
	}
	
	debug() << imie(groups);
	
	for(int i = 0; i < 2 * pot; ++i) tr[i] = inf;
	vector<int> starty(groups.size() + 1);
	vector<int> deg(groups.size());
	for(int i = 0; i < (int) groups.size(); ++i) {
		deg[i] = 2 * groups[i].size();
		for(int j = 0; j < (int) groups[i].size(); ++j) {
			int where = pot + starty[i] + j;
			int value = groups[i][j];
			tr[where] = value;
			inv[value] = where - pot;
			which_group[value] = i;
		}
		starty[i+1] = starty[i] + groups[i].size();
	}
	
	set<pair<int,int>> secik;
	for(int i = 0; i < (int) groups.size(); ++i)
		secik.insert({deg[i], i});
	
	for(int i = pot - 1; i >= 1; --i)
		tr[i] = min(tr[2*i], tr[2*i+1]);
	
	
	printf("%lld\n", answer * 2);
	
	for(int who = 1; who <= n; ++who) {
		int g = which_group[who];
		//~ int where = inv[who];
		
		int total = 2 * (n - who + 1);
		
		//~ debug() << imie(who) imie(g) imie(total);
		
		//~ assert(deg[g] * 2 <= total);
		
		vector<pair<int,int>> they;
		
		if(deg[g] * 2 != total && secik.rbegin() -> first * 2 == total
				&& !(is_soft && secik.rbegin() -> second == which_group[root])) {
			debug() << "A";
			int big = secik.rbegin() -> second;
			they.push_back({starty[big], starty[big+1] - 1});
		}
		else {
			debug() << "B";
			if(who == root && is_soft) {
				they.push_back({0, starty.back()});
			}
			else {
				they.push_back({0, starty[g] - 1});
				they.push_back({starty[g+1], starty.back()});
			}
		}
		//~ debug() << imie(they);
		int best = inf;
		for(pair<int,int> p : they)
			best = min(best, get_min(p.first, p.second));
		//~ debug() << imie(best);
		assert(best != inf);
		int i = inv[best];
		//~ debug() << imie(i);
		assert(tr[pot+i] == best);
		tr[pot+i] = inf;
		//~ debug() << "tu";
		for(int x = (pot + i) / 2; x >= 1; x /= 2)
			tr[x] = min(tr[2*x], tr[2*x+1]);
		assert(which_group[best] != g || (who == root && is_soft));
		//~ debug() << "erasy";
		for(int gg : {g, which_group[best]}) {
			debug() << "zmniejsz" imie(gg);
			secik.erase({deg[gg], gg});
			--deg[gg];
			secik.insert({deg[gg], gg});
		}
		//~ debug() << "done";
		printf("%d ", best);
	}
	puts("");
	
}