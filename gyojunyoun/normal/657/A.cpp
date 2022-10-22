#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[sz(V)-2])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define upmax(a,b) (a)=max((a),(b))
#define upmin(a,b) (a)=min((a),(b))
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
void fuk() { puts("-1"); exit(0); }

const int MAXN = 100005;

int N, H, D;

int main() {
	cin >> N >> D >> H;
	if(H == D) {
		if(N-1 == H) {
            for(int i = 1; i < N; i++)
                printf("%d %d\n", i, i+1);
			return 0;
		}
		if(2 == N || 1 == H) fuk();
		for(int i = 1; i <= H; i++)
			printf("%d %d\n", i, i+1);
		for(int i = H+2; i <= N; i++)
			printf("%d %d\n", H, i);
		return 0;
	}
	if(2*H < D) fuk();
	for(int i = 1; i <= H; i++)
		printf("%d %d\n", i, i+1);
	D -= H;
	for(int i = 1, pv = 1; i <= D; i++) {
		printf("%d %d\n", pv, i+H+1);
		pv = i+H+1;
	}
	for(int i = D+H+2; i <= N; i++)
		printf("1 %d\n", i);
	return 0;
}