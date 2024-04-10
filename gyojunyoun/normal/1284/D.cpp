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
inline void fuk() { puts("NO"); exit(0); }

const int MAXN = 100055;
const int MAXX = 200055;

vector<int> IV[MAXX], OV[MAXX];

int AS[MAXN], AE[MAXN];
int BS[MAXN], BE[MAXN];

int N;

void solve() {
	for(int i = 0; i < MAXX; i++) {
		IV[i].clear();
		OV[i].clear();
	}

	for(int i = 0; i < N; i++) {
		IV[AS[i]].eb(i);
		OV[AE[i]+1].eb(i);
	}

	multiset<int> SPQ, EPQ;
	for(int t = 0; t < MAXX; t++) {
		for(int i : OV[t]) {
			SPQ.erase(SPQ.find(BS[i]));
			EPQ.erase(EPQ.find(BE[i]));
		}
		for(int i : IV[t]) {
			SPQ.insert(BS[i]);
			EPQ.insert(BE[i]);
			if(*EPQ.begin() < BS[i]) fuk();
			if(BE[i] < *prev(SPQ.end())) fuk();
		}
	}
}

void comp(int A[], int B[]) {
	vector<int> V;
	for(int i = 0; i < N; i++) {
		V.eb(A[i]);
		V.eb(B[i]);
	}
	sorv(V); univ(V);
	for(int i = 0; i < N; i++) {
		A[i] = int(lower_bound(allv(V), A[i]) - V.begin());
		B[i] = int(lower_bound(allv(V), B[i]) - V.begin());
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> AS[i] >> AE[i];
		cin >> BS[i] >> BE[i];
	}

	comp(AS, AE); comp(BS, BE);

	solve();

	for(int i = 0; i < N; i++) {
		swap(AS[i], BS[i]);
		swap(AE[i], BE[i]);
	}

	solve();

	puts("YES");
	return 0;
}