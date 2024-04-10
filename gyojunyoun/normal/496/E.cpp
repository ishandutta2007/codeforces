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

struct EVT {
	EVT(int idx, int t, int x, int y)
		: idx(idx), t(t), x(x), y(y) {}
	int idx, t, x, y;

	bool operator < (const EVT &q) const {
		if(x != q.x) return x < q.x;
		if(t != q.t) return t < q.t;
		return y < q.y;
	}
};

vector<EVT> EV;
set<pii> PQ;

int A[MAXN], B[MAXN], C[MAXN];
int D[MAXK], E[MAXK];

int Ans[MAXK];
int N, K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K;
	for(int i = 1; i <= K; i++) cin >> D[i] >> E[i];
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];

	for(int i = 1; i <= K; i++) EV.eb(i, 1, D[i], E[i]);
	for(int i = 1; i <= N; i++) EV.eb(i, 0, A[i], B[i]);
	sorv(EV);
	for(auto &ev : EV) {
		int idx = ev.idx;
		if(!ev.t) {
			PQ.insert({B[idx], idx});
			continue;
		}
		auto it = PQ.lower_bound({E[idx], -1});
		if(PQ.end() == it) {
			puts("NO");
			exit(0);
		}
		int p = it->second;
		if(!--C[p]) PQ.erase(it);
		Ans[idx] = p;
	}

	cout << "YES\n";
	for(int i = 1; i <= K; i++)
		cout << Ans[i] << ' ';
	cout << '\n';
	return 0;
}