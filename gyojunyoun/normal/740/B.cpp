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
#define MAXN (555)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

ll A[MAXN];
ll Ans;
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) A[i] += A[i-1];
	for(int a, b; K--;) {
		scanf("%d%d", &a, &b);
		ll sum = A[b] - A[a-1];
		if(sum < 0) continue;
		Ans += sum;
	}
	printf("%lld\n", Ans);
	return 0;
}