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

const int MAXN = 200'055;

int ud[MAXN];

int uf(int i) { return i == ud[i] ? i : (ud[i] = uf(ud[i])); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }

vector<int> G[MAXN];

int A[MAXN], B[MAXN];

bool Ans[MAXN];

int N, M;

int dfs(int i, int ev, int p) {
	for(int e : G[i]) {
		int v = A[e] ^ B[e] ^ i;
		if(v == p) continue;
		if(v == ev) return e;
		int t = dfs(v, ev, i);
		if(t) return e;
	}
	return 0;
}

void run() {
	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
	}

	iota(ud, ud+N+5, 0);

	for(int i = 1; i <= M; i++) {
		if(uf(A[i]) != uf(B[i])) {
			Ans[i] = true;
			uf(A[i], B[i]);
			G[A[i]].eb(i);
			G[B[i]].eb(i);
		} else {
			Ans[i] = false;
		}
	}

	if(N+2 == M) {
		vector<int> EV;
		for(int i = 1; i <= M; i++)
			if(!Ans[i]) EV.eb(i);

		vector<int> VV;
		for(int e : EV) {
			VV.eb(A[e]);
			VV.eb(B[e]);
		}
		sorv(VV); univ(VV);

		if(3 == sz(VV)) {
			int ce = EV[0];
			int a = A[ce];
			int b = B[ce];

			int e = dfs(a, b, -1);

			Ans[e] = false;

			Ans[ce] = true;
		}
	}

	for(int i = 1; i <= M; i++) putchar(Ans[i] ? '1' : '0');
	puts("");


	for(int i = N; i; i--) G[i].clear();
	for(int i = M; i; i--) Ans[i] = false;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) run();

	return 0;
}