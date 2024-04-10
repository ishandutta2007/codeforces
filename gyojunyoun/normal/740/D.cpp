#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define MAXN (200005)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

vector<pii> G[MAXN];
vector<pli> V;
int d[MAXN], S[MAXN];
int A[MAXN], P[MAXN], W[MAXN];
bool chk[MAXN];
int N;

void dfs(int idx) {
	chk[idx] = true;
	const ll L = V.back().first;
	d[idx]++;
	int s = 0, e = sz(V)-1; for(int m; s < e;) {
		m = (s+e)/2;
		if(L-V[m].first <= A[idx]) e = m;
		else s = m+1;
	}
	d[P[V[s].second]]--;
	for(pii& e : G[idx]) {
		if(chk[e.first]) continue;
		V.pb({L + e.second, e.first});
		dfs(e.first);
		V.pop_back();
	}
}
void f(int idx) {
	chk[idx] = true;
	S[idx] = d[idx];
	for(pii& e : G[idx]) {
		if(chk[e.first]) continue;
		f(e.first);
		S[idx] += S[e.first];
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 2; i <= N; i++) {
		scanf("%d%d", &P[i], &W[i]);
		fg(G, i, P[i], W[i]);
	}
	V.pb({1, 0ll});
	dfs(1);
	fill(chk, chk+MAXN, false);
	f(1);
	for(int i = 1; i <= N; i++) printf("%d ", S[i] - 1);
	puts("");
	return 0;
}