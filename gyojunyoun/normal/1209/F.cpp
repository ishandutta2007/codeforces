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

const int MOD = 1000000007;
const int MAXN = 100055;
const int MAXM = 100055;
const int MAXC = 600055;

int dgl[MAXM], pw10[9];

int rel[MAXN], bcd[MAXN], bidx[MAXN];

vector<pii> G[MAXN];
vector<int> CV[MAXC];

ll Ans[MAXN];
int A[MAXM], B[MAXM];
int C[MAXN];

int N, M;

void precal() {
	for(int s = 0, e = 1, g = 0;; e++) {
		if(e >= MAXC) break;
		for(int v : CV[e]) {
			rel[v] = INF;
			for(auto &ed : G[v]) {
				int idx, dst;
				tie(idx, dst) = ed;
				dst = C[idx] + dgl[dst];
				if(dst != C[v]) continue;
				dst = ed.second;

				int nrel = rel[idx];
				int nbcd = bcd[idx] * pw10[dgl[dst]] + dst;

				if(pii(nrel, nbcd) < pii(rel[v], bcd[v])) {
					rel[v] = nrel;
					bcd[v] = nbcd;
					bidx[v] = idx;
				}
			}
		}

		if(e-s < 6) continue;

		s++;
		vector<pii> O;
		for(int i = s; i <= e; i++) for(int v : CV[i]) {
			int key = rel[v]*10 + bcd[v]/pw10[i-s];
			bcd[v] %= pw10[i-s];
			O.eb(key, v);
		}
		sorv(O);
		for(int p = 0, q, n = sz(O), cnt = 0; p < n; p = q) {
			for(q = p; q < n && O[p].first == O[q].first; q++)
				rel[O[q].second] = cnt;
			cnt++;
		}
	}

	for(int i = 1; i < MAXC; i++) {
		for(int v : CV[i]) {
			int pv = bidx[v];
			for(auto &ed : G[v]) {
				int idx, dst;
				tie(idx, dst) = ed;
				if(idx != pv) continue;

				Ans[v] = (Ans[idx] * pw10[dgl[dst]] + dst) % MOD;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pw10[0] = 1;
	for(int i = 1; i < 9; i++) pw10[i] = pw10[i-1] * 10;

	cin >> N >> M;
	for(int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		fg(G, A[i], B[i], i);
	}
	for(int i = 1; i <= M; i++) {
		int &ret = dgl[i];
		for(int j = i; j; j /= 10) ret++;
	}

	{
		fill(C+2, C+N+1, INF);
		priority_queue<pii, vector<pii>, greater<pii>> PQ;
		PQ.emplace(0, 1);
		for(int idx, dst; !PQ.empty();) {
			tie(dst, idx) = PQ.top(); PQ.pop();
			for(auto &ed : G[idx]) {
				int ndst, nidx;
				tie(nidx, ndst) = ed;
				ndst = dst + dgl[ndst];
				if(C[nidx] <= ndst) continue;
				C[nidx] = ndst;
				PQ.emplace(ndst, nidx);
			}
		}
	}

	for(int i = 1; i <= N; i++) CV[C[i]].eb(i);
	precal();

	for(int i = 2; i <= N; i++)
		cout << Ans[i] << '\n';
	return 0;
}