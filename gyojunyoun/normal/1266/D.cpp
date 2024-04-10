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

const int MAXN = 100055;

struct EDG {
	EDG(int a, int b, ll c)
		: a(a), b(b), c(c) {}
	int a, b; ll c;
};


vector<EDG> AnsV;


ll A[MAXN];

int N, M;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for(int a, b, c; M--;) {
		cin >> a >> b >> c;
		A[a] -= c;
		A[b] += c;
	}

	vector<int> PV, MV;
	for(int i = 1; i <= N; i++) {
		if(A[i] > 0) PV.eb(i);
		if(A[i] < 0) MV.eb(i);
	}

	for(int n = sz(PV), m = sz(MV), i = 0, j = 0; i < n || j < m;) {
		ll c = min(A[PV[i]], -A[MV[j]]);
		A[PV[i]] -= c; A[MV[j]] += c;
		AnsV.eb(MV[j], PV[i], c);
		if(!A[PV[i]]) i++;
		if(!A[MV[j]]) j++;
	}

	cout << sz(AnsV) << '\n';
	for(auto  &v : AnsV) {
		cout << v.a << ' ' << v.b << ' ' << v.c << '\n';
	}
	return 0;
}