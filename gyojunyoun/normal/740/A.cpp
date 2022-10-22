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

int N, A, B, C;
ll Ans = INFLL;

int main() {
	scanf("%d%d%d%d", &N, &A, &B, &C);
	for(int a = 0; a < 4; a++) for(int b = 0; b < 4; b++) for(int c = 0; c < 4; c++) {
		const int K = N + a + 2*b + 3*c;
		if(K%4) continue;
		ll cost = (ll)A*a + (ll)B*b + (ll)C*c;
		upmin(Ans, cost);
	}
	printf("%lld\n", Ans);
	return 0;
}