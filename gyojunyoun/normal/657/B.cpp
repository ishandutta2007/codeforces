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

const int MAXN = 200005;

ll B[MAXN], C[MAXN];
bitset<MAXN> isB, isC;

ll A[MAXN];

ll K;
int N, Ans;

int main() {
    //freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for(int i = 0; i <= N; i++) cin >> A[i];

	{
		if(A[0] % 2) {
			isB[0] = true;
		} else {
			B[0] = A[0] / 2;
		}

		for(int i = 1; i <= N; i++) {
			ll t = B[i-1] + A[i];
			if(t % 2) {
				isB[i] = true;
			} else {
				B[i] = t/2;
				isB[i] = isB[i-1];
			}
		}
	}

	{
		C[N] = A[N] * 2;
		for(int i = N-1; 0 <= i; i--) {
			C[i] = (C[i+1] + A[i]) * 2;
			if(1000000000000000000ll < abs(C[i])) {
				isC[i] = true;
			} else {
				isC[i] = isC[i+1];
			}
		}
	}

	for(int i = 0; i <= N; i++) {
		ll as = 0, bs = 0;
		if(i < N) {
			as = C[i+1];
			if(isC[i+1]) continue;
		}
		if(i) {
			bs = B[i-1];
			if(isB[i-1]) continue;
		}
		ll t = as + bs;

		//printf("i=%d, as=%lld, bs=%lld, t=%lld\n", i, as, bs, t);
		if(K < abs(t)) continue;
		if(i == N && !t) continue;

		Ans++;
	}

	cout << Ans << endl;
	return 0;
}