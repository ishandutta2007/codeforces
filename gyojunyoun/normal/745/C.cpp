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
#define MAXN (1005)
#define MAXK (1005)
#define MAXM (100005)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

vector<int> G[MAXN];
vector<int> V;
int A[MAXM], B[MAXM];
int C[MAXK];
int ud[MAXN], cnt[MAXN], udsz[MAXN];
bool isC[MAXN];
int N, M, K;
ll Ans;

int uf(int i) { return i == ud[i] ? i : ud[i] = uf(ud[i]); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }
int main() {
	iota(ud, ud+MAXN, 0);
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= K; i++) scanf("%d", &C[i]);
	for(int i = 1; i <= M; i++) scanf("%d%d", &A[i], &B[i]);
	for(int i = 1; i <= M; i++) uf(A[i], B[i]);
	for(int i = 1; i <= N; i++) G[uf(i)].pb(i);
	for(int i = 1; i <= K; i++) isC[uf(C[i])] = true;
	for(int i = 1; i <= M; i++) cnt[uf(A[i])]++;
	for(int i = 1; i <= N; i++) udsz[uf(i)]++;
	for(int i = 1; i <= N; i++) {
		if(G[i].empty()) continue;
		if(!isC[i]) continue;
		V.pb(udsz[i]);
		Ans += (ll)udsz[i] * (udsz[i]-1) / 2 - cnt[i];
	}
	sorv(V); revv(V);
	for(int i = 1; i <= N; i++) {
		if(G[i].empty()) continue;
		if(isC[i]) continue;
		Ans += (ll)udsz[i] * (udsz[i]-1) / 2 - cnt[i];
		Ans += (ll)V[0] * udsz[i];
		V[0] += udsz[i];
	}
	printf("%lld\n", Ans);
	return 0;
}