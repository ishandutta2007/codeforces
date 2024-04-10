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

typedef long long ll;

const ll INF = 1e18L + 5;
const int nax = 3e5 + 5;

struct S {
	ll score;
	pair<int,int> last_state;
	vector<int> moves;
};

bool done[nax][2];
S dp[nax][2];
int in[nax], memo[nax];

ll rec(int n, int anything) {
	if(n == 0) return 0;
	assert(n >= 1);
	if(done[n][anything]) return dp[n][anything].score;
	done[n][anything] = true;
	dp[n][anything].score = INF;
	if(anything) {
		rec(n, 0);
		dp[n][anything] = dp[n][0];
	}
	auto consider = [&] (vector<int> moves) {
		int first = n;
		for(int x : moves) first = min(first, x);
		if(first < 1) return;
		for(int i = first; i <= n; ++i) in[i] = memo[i];
		ll cost = 0;
		for(int x : moves) {
			int here = min(in[x], in[x+1]);
			if(here == 0) return;
			cost += here;
			in[x] -= here;
			in[x+1] -= here;
		}
		if(!anything && in[n]) return;
		for(int i = first; i < n; ++i)
			if(in[i] && in[i+1]) return;
		bool ple = in[first] == 0;
		cost += rec(first - 1, ple);
		if(cost < dp[n][anything].score) {
			dp[n][anything].score = cost;
			dp[n][anything].last_state = {first - 1, ple};
			dp[n][anything].moves = moves;
		}
	};
	//~ consider({});
	//~ consider({n-1});
	//~ consider({n-1,n-2});
	//~ consider({n-2,n-1});
	//~ consider({n-3,n-2,n-1});
	//~ consider({n-2,n-3,n-1});
	//~ consider({n-1,n-2,n-3});
	//~ consider({n-1,n-3,n-2});
	//~ consider({n-2,n-1,n-3});
	//~ consider({n-3,n-1,n-2});
	
	//~ consider({n-3,n-1,n-2});
	//~ consider({n-1,n-3,n-2});
	
	consider({});
	consider({n-1});
	consider({n-2, n-1});
	consider({n-1, n-2});
	consider({n-1, n-2, n-3});
	consider({n-3, n-2, n-1});
	consider({n-1, n-3, n-2});
	
	
	consider({n-4,n-3,n-2,n-1});
	consider({n-1,n-2,n-3,n-4});
	consider({n-1,n-2,n-4,n-3});
	consider({n-1,n-4,n-3,n-2});
	
	if(0)for(int len = 0; len <= 3; ++len) {
		vector<int> moves(len);
		for(int i = 1; i <= len; ++i)
			moves[i-1] = n - i;
		sort(moves.begin(), moves.end());
		do {
			consider(moves);
		} while(next_permutation(moves.begin(), moves.end()));
	}
	debug() << imie(n) imie(anything) imie(dp[n][anything].score);
	if(anything) assert(dp[n][anything].score < INF);
	return dp[n][anything].score;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		memo[i] = in[i];
	}
	vector<int> moves;
	rec(n, 1);
	pair<int,int> p{n, 1};
	while(p.first) {
		for(int x : dp[p.first][p.second].moves) moves.push_back(x);
		p = dp[p.first][p.second].last_state;
	}
	printf("%d\n", (int) moves.size());
	for(int x : moves) printf("%d\n", x);
}