#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;

ll value[nax];
vi w[nax];
ll answer;

struct T {
	ll top, below, combo;
};

ll one(multiset<ll> & s) {
	if(s.empty()) return 0;
	auto it = s.end();
	--it;
	return *it;
}
ll two(multiset<ll> & s) {
	if(s.empty()) return 0;
	auto it = s.end();
	--it;
	ll r = *it;
	if(it == s.begin()) return r;
	--it;
	return r + *it;
} 

T dfs(int a, int par) {
	maxi(answer, value[a]);
	vector<T> they;
	for(int b : w[a]) if(b != par)
		they.pb(dfs(b, a));
	if(they.empty()) return T{value[a], value[a], value[a]};
	multiset<ll> topy, belowy, comby;
	for(T & t : they) {
		topy.insert(t.top);
		belowy.insert(t.below);
		comby.insert(t.combo);
	}
	T me = T{value[a], value[a], value[a]};
	for(T & t : they) {
		topy.erase(topy.find(t.top));
		belowy.erase(belowy.find(t.below));
		comby.erase(comby.find(t.combo));
		
		maxi(answer, t.below + two(topy) + value[a]);
		maxi(answer, t.below + one(belowy));
		maxi(me.top, t.top + value[a]);
		maxi(me.combo, t.combo + value[a]);
		maxi(me.combo, t.below + value[a] + one(topy));
		maxi(me.below, t.below);
		maxi(me.below, t.top + value[a]);
		maxi(me.below, t.top + value[a] + one(topy));
		maxi(answer, t.combo + value[a] + one(topy));
		
		topy.insert(t.top);
		belowy.insert(t.below);
		comby.insert(t.combo);
	}
	maxi(me.below, me.top);
	maxi(me.combo, me.below);
	maxi(answer, max(me.top, max(me.below, me.combo)));
	return me;
}

int n;
ll brute_ans = 0;

bool vis[nax];

void dfs_two(int a, ll so_far) {
	so_far += value[a];
	maxi(brute_ans, so_far);
	vis[a] = true;
	for(int b : w[a]) if(!vis[b]) dfs_two(b, so_far);
	vis[a] = false;
}

void dfs_one(int a, ll so_far) {
	so_far += value[a];
	maxi(brute_ans, so_far);
	vis[a] = true;
	RI(i,n) if(!vis[i]) dfs_two(i, so_far);
	for(int b : w[a]) if(!vis[b]) dfs_one(b, so_far);
	vis[a] = false;
}
	

ll brute() {
	RI(i, n) dfs_one(i, 0LL);
	return brute_ans;
}

int main(int argc, char * argv[]) {
	//int seed = atoi(argv[1]);
	//srand(seed);
	//n = 8;
	scanf("%d", &n);
	RI(i, n) scanf("%lld", &value[i]);
	//RI(i, n) printf("%lld ", value[i]); puts("");
	FOR(i, 2, n) {
		int a, b;
		//a = i;
		//b = rand() % (i - 1) + 1;
		//printf("%d %d\n", a, b);
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	dfs(1, -1);
	printf("%lld\n", answer);
	/*ll tmp = brute();
	if(tmp != answer) {
		printf("%d\n", seed);
		printf("%lld %lld\n", tmp, answer);
		assert(false);
	}*/
	//printf("%lld\n", answer);
	//printf("%lld\n", brute());
	return 0;
}