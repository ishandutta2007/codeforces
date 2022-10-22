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
#define MAXM (100005)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int d[MAXN];
int A[MAXM], B[MAXM];
int N, M, Ans = INF;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		const int L = B[i] - A[i] + 1;
		upmin(Ans, L);
	}
	for(int i = 1; i <= N; i++) d[i] = i % Ans;
	printf("%d\n", Ans);
	for(int i = 1; i <= N; i++) printf("%d ", d[i]);
	puts("");
	return 0;
}