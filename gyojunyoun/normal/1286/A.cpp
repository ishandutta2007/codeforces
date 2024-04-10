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

const int MAXN = 100055;

int A[MAXN];

int _O, _E;
int N, O, E, Ans;

void solve() {
	O = (N+1)/2 - _O;
	E = N/2 - _E;

	{
		bool flag = false;
		for(int i = 1; i <= N; i++)
			if(A[i]) flag = true;
		if(!flag) {
			puts("1");
			exit(0);
		}
	}

	vector<pii> EOV, EV, OV;
	{
		int pv = 0;
		for(int i = 1; i <= N+1; i++) {
			if(!A[i]) continue;
			{
				bool pvo = 1 == A[pv];
				bool io = 1 == A[i];
				if(pvo == io) {
					(pvo ? OV : EV).eb(pv+1, i-1);
				} else {
					EOV.eb(pv+1, i-1);
				}
			}
			pv = i;
		}
	}

	vector<int> EOL, EL, OL;
	for(auto &v : EOV) if(v.fi <= v.se) EOL.eb(v.se - v.fi + 1);
	for(auto &v : EV) if(v.fi <= v.se) EL.eb(v.se - v.fi + 1);
	for(auto &v : OV) if(v.fi <= v.se) OL.eb(v.se - v.fi + 1);

	sorv(EOL); sorv(EL); sorv(OL);

	for(int v : EL) {
		if(E < v) {
			Ans += 2;
			continue;
		}
		E -= v;
	}
	for(int v : OL) {
		if(O < v) {
			Ans += 2;
			continue;
		}
		O -= v;
	}
	Ans += sz(EOL);

	for(int i = 2; i <= N; i++) {
		if(!A[i-1] || !A[i]) continue;
		if(A[i-1] != A[i]) Ans++;
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	if(1 == N) {
		puts("0");
		exit(0);
	}
	if(2 == N) {
		puts("1");
		exit(0);
	}
	for(int i = 1; i <= N; i++) {
		int c; cin >> c;
		if(!c) continue;
		c %= 2;
		if(!c) c = 2;
		A[i] = c;
		if(1 == c) _O++;
		else _E++;
	}

	int ret = INF;

	Ans = 0;
	A[0] = 1; A[N+1] = 1;
	solve();
	upmin(ret, Ans);


	A[0] = 1; A[N+1] = 2;
	Ans = 0;
	solve();
	upmin(ret, Ans);


	A[0] = 2; A[N+1] = 1;
	Ans = 0;
	solve();
	upmin(ret, Ans);


	A[0] = 2; A[N+1] = 2;
	Ans = 0;
	solve();
	upmin(ret, Ans);

	cout << ret << endl;
	return 0;
}