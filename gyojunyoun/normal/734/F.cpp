#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p++=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define eb emplace_back
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
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-7;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].eb(b); G[b].eb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].eb(b, c); G[b].eb(a, c); }
inline void fuk() { puts("-1"); exit(0); }

const int MAXN = 200055;

ll A[MAXN], B[MAXN], C[MAXN];
int D[30];

ll K;
int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> B[i];
	for(int i = 1; i <= N; i++) cin >> C[i];

	for(int i = 1; i <= N; i++) K += B[i] + C[i];
	if(K % (N*2)) fuk();
	K /= N*2;
	for(int i = 1; i <= N; i++) {
		A[i] = (B[i] + C[i] - K);
		if(A[i] % N) fuk();
		A[i] /= N;
		if(A[i] >= INF) fuk();
	}

	for(int i = 1; i <= N; i++)
		for(int j = 0; j < 30; j++)
			if(A[i]>>j & 1) D[j]++;
	
	for(int i = 1; i <= N; i++) {
		ll c = 0;
		for(int j = 0; j < 30; j++) if(A[i]>>j & 1)
			c += ll(D[j]) << j;
		if(B[i] != c) fuk();
		c = 0;
		for(int j = 0; j < 30; j++) {
			if(A[i]>>j & 1) c += ll(N) << j;
			else c += ll(D[j]) << j;
		}
		if(C[i] != c) fuk();
	}

	for(int i = 1; i <= N; i++)
		cout << A[i] << ' ';
	cout << '\n';
	return 0;
}