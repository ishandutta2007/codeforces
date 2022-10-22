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

struct EVT {
	EVT(int type, int x, int idx)
		: type(type), x(x), idx(idx) {}
	int type, x, idx;

	bool operator < (const EVT &t) const {
		if(x != t.x) return x < t.x;
		return type < t.type;
	}
};

ll A[MAXN];

ll Ans = INFLL;
int N, K, b, c;

int f(ll n) { return ((n % 5) + 5) % 5; }

int main() {
    //freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	cin >> N >> K >> b >> c;
	for(int i = 1; i <= N; i++) cin >> A[i];
	sort(A+1, A+N+1);

	{
		ll S[5] = {0, };
		int C[5] = {0, };
		ll sum = 0;

		for(int i = 0; i < K; i++) {
            sum += A[i];
            C[f(A[i])]++;
            S[f(A[i])] += A[i];
		}

		for(int i = 1; i+K-1 <= N; i++) {
			C[f(A[i-1])]--; C[f(A[i+K-1])]++;
			S[f(A[i-1])] -= A[i-1]; S[f(A[i+K-1])] += A[i+K-1];
			sum -= A[i-1]; sum += A[i+K-1];

			for(int y = A[i+K-1]; y < A[i+K-1]+5; y++) {
				upmin(Ans, (ll(K)*y - sum) * c);

				ll ret = 0;
				for(int x = 0; x < 5; x++) {
					int z = f(y-x);
					ll tmp = ll(y) * C[x] - S[x];
					tmp -= ll(z) * C[x];
					if(tmp % 5) puts("SEX");
					tmp /= 5;
					ret += tmp * b;
				}
				for(int x = 0; x < 5; x++) {
					int z = f(y-x);
					ret += ll(z) * C[x] * c;
				}

				upmin(Ans, ret);
			}
		}
	}

	{
		vector<EVT> EV;
		for(int i = 1; i <= N; i++) {
			EV.eb(0, A[i], i);
			for(int x = A[i]; x < A[i]+5; x++)
				EV.eb(1, x, 0);
		}
		sorv(EV);

		multiset<ll> PQ; ll SUM = 0;
		for(int tx = 0; tx < 5; tx++) {
			for(auto &e : EV) {
				if(!e.type) {
					int idx = e.idx, z = f(tx - f(A[idx]));
					ll t = (-A[idx]-z);
					t *= b;
					t += ll(z) * c * 5;
					PQ.insert(t);
					SUM += t;

					if(K < sz(PQ)) {
						auto it = PQ.end(); it--;
						SUM -= *it;
						PQ.erase(it);
					}
				} else {
					int y = e.x;
					if(sz(PQ) < K) continue;
					if(f(y) != tx) continue;

					ll t = ll(y) * K * b;
					t += SUM;
					if(t % 5) puts("SEXX");
					t /= 5;
					upmin(Ans, t);
				}
			}

			PQ.clear(); SUM = 0;
		}
	}

	cout << Ans << endl;
	return 0;
}