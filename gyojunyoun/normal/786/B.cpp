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

const int MX = 131072;

vector<pii> G[MX*5];
ll D[MX*5];

int N, Q, K;

void runDijk() {
	priority_queue<pli, vector<pli>, greater<pli>> PQ;
	D[K] = 0; PQ.emplace(0, K);
	for(ll dst; !PQ.empty();) {
		int idx; tie(dst, idx) = PQ.top(); PQ.pop();
		if(D[idx] < dst) continue;
		for(auto &ed : G[idx]) {
			ll ndst = dst + ed.second;
			int nidx = ed.first;
			if(D[nidx] <= ndst) continue;
			D[nidx] = ndst;
			PQ.emplace(ndst, nidx);
		}
	}
}

vector<int> interval(int s, int e) {
	vector<int> V;
	for(s += MX, e += MX; s <= e; s >>= 1, e >>= 1) {
		if(s&1) V.eb(s++);
		if(~e&1) V.eb(e--);
	}
	return V;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for(int i = 1; i <= MX; i++) {
		G[i].eb(MX*2+i-1, 0);
		G[MX*4+i-2].eb(i, 0);
	}
	for(int i = 2; i < MX*2; i++) {
		G[i+MX].eb(i/2+MX, 0);
		G[i/2+MX*3-1].eb(i+MX*3-1, 0);
	}
	fill(D, D+MX*5, INFLL);

	cin >> N >> Q >> K;
	for(int t, a, b, c, w; Q--;) {
		cin >> t;
		if(1 == t) {
			cin >> a >> b >> w;
			G[a].eb(b, w);
		} else if(2 == t) {
			cin >> a >> b >> c >> w;
			for(int v : interval(b-1, c-1))
				G[a].eb(v+MX*3-1, w);
		} else {
			cin >> a >> b >> c >> w;
			for(int v : interval(b-1, c-1))
				G[v+MX].eb(a, w);
		}
	}

	runDijk();

	for(int i = 1; i <= N; i++)
		cout << (INFLL <= D[i] ? -1 : D[i]) << ' ';
	cout << '\n';
	return 0;
}