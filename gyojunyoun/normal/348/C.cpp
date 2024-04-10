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
const int MAXK = 100055;
const int SQRN = 320;

vector<int> G[MAXK];
int DG[MAXK];

vector<int> TV;
bitset<MAXK> isT;
ll B[MAXK], D[MAXK];

int C[MAXK][SQRN];
ll A[MAXN];

int N, K, Q, T;

void precal() {
	for(int i = 1; i <= N; i++)
		if(isT[i] = DG[i] >= SQRN) TV.eb(i);
	T = sz(TV);

	bitset<MAXN> chk;
	for(int tvi = 0, t; tvi < T; tvi++) {
		t = TV[tvi];
		for(int v : G[t]) {
			B[t] += A[v];
			chk[v] = true;
		}
		for(int i = 1; i <= N; i++) {
			int cnt = 0;
			for(int v : G[i]) if(chk[v]) cnt++;
			C[i][tvi] = cnt;
		}
		chk.reset();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= K; i++) {
		cin >> DG[i];
		for(int j = DG[i], c; j--;) {
			cin >> c;
			G[i].eb(c);
		}
	}
	precal();

	for(int a, b; Q--;) {
		char t; cin >> t >> a;
		if('?' == t) {
			if(isT[a]) {
				ll ret = B[a];
				for(int i = T; i--;) if(TV[i] != a)
					ret += D[TV[i]] * C[a][i];
				cout << ret << '\n';
				continue;
			}
			ll ret = 0;
			for(int v : G[a]) ret += A[v];
			for(int i = T; i--;) ret += D[TV[i]] * C[a][i];
			cout << ret << '\n';
		} else {
			cin >> b;
			if(isT[a]) {
				B[a] += ll(b) * DG[a];
				D[a] += b;
				continue;
			}
			for(int v : G[a]) A[v] += b;
			for(int i = T; i--;) B[TV[i]] += C[a][i] * b;
		}
	}
	return 0;
}