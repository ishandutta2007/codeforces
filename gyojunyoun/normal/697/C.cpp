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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

map<ll, ll> Q;
int N;

void f(vector<ll>& V, ll X) {
	clv(V);
	for(; X; X /= 2) V.pb(X);
}
ll g(vector<ll> &A, vector<ll>& B) {
	for(int i = 0; i < sz(A); i++)
		for(ll v : B) if(A[i] == v) return v;
	return -1;
}
int main() {
	for(scanf("%d", &N); N--;) {
		int type; ll u, v, w; scanf("%d%lld%lld", &type, &u, &v);
		vector<ll> A, B; f(A, u); f(B, v);
		const ll lca = g(A, B);
		if(1 == type) { 
			scanf("%lld", &w);
			for(ll x = u; x != lca; x /= 2) Q[x] += w;
			for(ll x = v; x != lca; x /= 2) Q[x] += w;
		} else {
			ll ret = 0;
			for(ll x = u; x != lca; x /= 2) {
				if(Q.count(x) == 0) continue;
				ret += Q[x];
			}
			for(ll x = v; x != lca; x /= 2) {
				if(Q.count(x) == 0) continue;
				ret += Q[x];
			}
			printf("%lld\n", ret);
		}
	}
	return 0;
}