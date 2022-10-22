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

const int MAXN = 200055;
const int MAXM = 200055;

vector<int> G[MAXN];
bitset<MAXN> isD;
int prt[MAXN];

vector<int> RtV;
int A[MAXN];
int B[MAXM], C[MAXM];

bitset<MAXN> chk;
ll dp[MAXN];

ll Ans, Sum;
int N, M, K;

void dfs(int i) {
	chk[i] = true;
	for(int v : G[i]) if(!chk[v]) {
		dfs(v);
		upmax(dp[i], dp[v]);
	}
	dp[i] += A[i];
}

void precal() {
	if(M == N-1) {
		for(int i = 1; i <= N; i++)
			if(i != K) isD[i] = true;
		return;
	}

	vector<int> V;
	int Dg[MAXN] = {0, };

	for(int i = 1; i <= N; i++) {
		Dg[i] = sz(G[i]);
		if(1 == Dg[i]) {
			V.eb(i);
			isD[i] = true;
		}
	}

	for(int i; !V.empty();) {
		i = V.back(); V.pop_back();

		for(int v : G[i]) if(!isD[v]) {
			prt[i] = v;
			if(1 == --Dg[v]) {
				isD[v] = true;
				V.eb(v);
			}
		}
	}

	for(int i = K; i && isD[i]; i = prt[i]) isD[i] = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1, a, b; i <= M; i++) {
		cin >> a >> b;
		B[i] = a; C[i] = b;
		fg(G, a, b);
	}
	if(1 == N) {
		cout << A[1] << endl;
		exit(0);
	}
	cin >> K;

	precal();

	for(int i = 1; i <= N; i++) if(!isD[i]) {
		Sum += A[i];
		for(int v : G[i]) if(isD[v])
			RtV.eb(v);
	}
	sorv(RtV); univ(RtV);

	for(int i = 1; i <= N; i++) G[i].clear();
	for(int i = 1, a, b; i <= M; i++) {
		a = B[i]; b = C[i];
		if(!isD[a] || !isD[b]) continue;
		fg(G, a, b);
	}

	for(int v : RtV) {
		dfs(v);
		upmax(Ans, dp[v]);
	}

	cout << Ans+Sum << endl;
	return 0;
}