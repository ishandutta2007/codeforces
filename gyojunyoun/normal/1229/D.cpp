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

struct DJF {
	DJF() { init(); }
	int ud[120], uc[120];

	void init() { 
		iota(ud, ud+120, 0);
		fill(uc, uc+120, 1);
	}
	int uf(int i) { return i == ud[i] ? i : (ud[i] = uf(ud[i])); }
	void uf(int a, int b) {
		a = uf(a); b = uf(b);
		if(a == b) return;
		uc[a] += uc[b];
		uc[b] = 0;
		ud[b] = a;
	}
	int get() { return uc[uf(0)]; }
};

map<vector<int>, int> MP;
int PD[120][120];

int A[MAXN];

ll Ans;
int N, K, KP;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	KP = 1; for(int i = 1; i <= K; i++) KP *= i;
	{
		vector<int> V;
		for(int i = 0; i < K; i++) V.eb(i);
		int cnt = 0;
		do {
			MP[V] = cnt;
			cnt++;
		} while(next_permutation(allv(V)));
	}
	for(auto &key1 : MP) {
		auto &V = key1.first;
		for(auto &key2 : MP) {
			auto &U = key2.first;
			vector<int> T(K);
			for(int i = 0; i < K; i++)
				T[V[i]] = U[i];
			PD[key1.second][key2.second] = MP[T];
		}
	}
	for(int i = 1; i <= N; i++) {
		vector<int> V;
		for(int j = 0; j < K; j++){
			int c; cin >> c;
			V.eb(c-1);
		}
		A[i] = MP[V];
	}

	vector<pair<DJF, int>> PQ;
	for(int i = 1; i <= N; i++) {
		PQ.eb(); PQ.back().second = 1;
		vector<pair<DJF, int>> TV;
		for(auto &v : PQ) {
			for(int j = KP; j--;)
				v.first.uf(j, PD[A[i]][j]);
			if(TV.empty() || TV.back().first.get() != v.first.get()) TV.eb(v);
			else TV.back().second += v.second;
		}
		for(auto &v : TV) Ans += ll(v.first.get()) * v.second;
		swap(PQ, TV);
	}

	cout << Ans << endl;
	return 0;
}