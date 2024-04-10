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
#define fi first
#define se second
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

const int MAXN = 200055;
const int MAXX = 500055;

vector<pii> G[MAXN];

int A[MAXN], B[MAXX];
bitset<MAXN> chk;

ll Ans;
int N, Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		vector<int> V;
		{
			int n = A[i], p = 2;
			for(; p*p <= n; p++) if(0 == n%p)
				for(V.eb(p); 0 == n%p; n /= p);
			if(1 < n) V.eb(n);
		}
		int n = sz(V); for(int key = 1<<n; key--;) {
			int r = 1, c = 1;
			for(int j = n; j--;) if(key>>j & 1) {
				c = -c;
				r *= V[j];
			}
			G[i].eb(r, c);
		}
	}

	for(int i; Q--;) {
		cin >> i;
		for(auto &v : G[i]) {
			if(chk[i]) {
				B[v.fi]--;
				Ans -= B[v.fi] * v.se;
			} else {
				Ans += B[v.fi] * v.se;
				B[v.fi]++;
			}
		}
		chk[i] = !chk[i];
		cout << Ans << '\n';
	}
	return 0;
}