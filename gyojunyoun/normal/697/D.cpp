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
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }

vector<int> G[MAXN];
ld d[MAXN];
int prt[MAXN], dep[MAXN], cnt[MAXN];
int N;

void f(int idx, int depth) {
	dep[idx] = depth;
	cnt[idx] = 1;
	for(int v : G[idx]) {
		if(dep[v]) continue;
		f(v, depth+1);
		cnt[idx] += cnt[v];
	}
}
void g(int idx) {
	for(int v : G[idx]) {
		if(v == prt[idx]) continue;
		d[v] = d[idx] + ((ld)(cnt[idx] - cnt[v] - 1))/2 + 1;
		g(v);
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 2; i <= N; i++) {
		scanf("%d", &prt[i]);
		fg(G, i, prt[i]);
	}
	f(1, 1);
	d[1] = 1; g(1);
	for(int i = 1; i <= N; i++) printf("%.8lf ", d[i]);
	puts("");
	return 0;
}