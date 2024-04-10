#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXN = 500055;

vector<int> G[MAXN];

int A[MAXN], C[MAXN];
int Ans[MAXN];
bitset<MAXN> chk;

int T, N;

void solve() {
	{
		vector<int> V;
		V.eb(N+1);
		for(int i = 1; i <= N; i++) {
			for(; V.back() == i; V.pop_back());
			if(-1 == A[i]) {
				A[i] = V.back();
				continue;
			}
			if(V.back() < A[i]) {
				puts("-1");
				return;
			}
			V.eb(A[i]);
		}
	}

	fill(C, C+N+2, 0);
	fill(Ans, Ans+N+2, 0);
	for(int i = 1; i <= N+1; i++) G[i].clear();
	for(int i = 1; i <= N; i++) {
		int a = i, b = A[i];
		G[a].eb(b);
		C[b]++;
	}

	priority_queue<int> PQ;
	for(int i = 1; i <= N; i++) if(!C[i]) PQ.push(i);
	for(int i, c = 1; !PQ.empty();) {
		i = PQ.top(); PQ.pop();
		if(N < i) continue;
		Ans[i] = c; c++;

		for(int v : G[i]) {
			C[v]--;
			if(!C[v]) PQ.push(v);
		}
	}

	chk.reset();
	for(int i = 1; i <= N; i++) {
		if(Ans[i] < 1 || N < Ans[i] || chk[Ans[i]]) {
			puts("-1");
			return;
		}
		chk[Ans[i]] = true;
	}

	for(int i = 1; i <= N; i++) printf("%d ", Ans[i]);
	puts("");
}

int main() {
	ios::sync_with_stdio(false);

	cin >> T;
	for(int ti = 0; ti < T; ti++) {
		cin >> N;
		for(int i = 1; i <= N; i++) cin >> A[i];
		solve();
	}
	return 0;
}