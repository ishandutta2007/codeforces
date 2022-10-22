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

const int MAXN = 2055;

vector<int> AnsV;

pii P[MAXN];
char A[MAXN];

int N;

void f(vector<int> &V, vector<int> &CV) {
	if(sz(V) < 3) return;
	swap(V[0], *min_element(allv(V), [&](int a, int b) {
		return P[a] < P[b];
	}));
	sort(V.begin()+1, V.end(), [&](int a, int b) {
		return 0 < ccw(P[V[0]], P[a], P[b]);
	});

	CV.clear();
	for(int v : V) {
		for(; 1 < sz(CV) && ccw(P[befv(CV)], P[CV.back()], P[v]) <= 0; CV.pop_back());
		CV.eb(v);
	}
}

void solve(vector<int> &V, int idx) {
	if(N < idx+2) {
		AnsV.eb(V[0]);
		return;
	}

	int p = AnsV.back();
	V.eb(p);
	vector<int> CV;
	f(V, CV);
	rotate(CV.begin(), find(allv(CV), p), CV.end());

	if('L' == A[idx]) {
		AnsV.eb(CV[1]);
		V.erase(find(allv(V), p));
		V.erase(find(allv(V), AnsV.back()));
	} else {
		AnsV.eb(CV.back());
		V.erase(find(allv(V), p));
		V.erase(find(allv(V), AnsV.back()));
	}
	solve(V, idx+1);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> P[i].first >> P[i].second;
	cin >> (A+1);

	{
		vector<int> V, CV;
		for(int i = 1; i <= N; i++) V.eb(i);
		f(V, CV);
		V.erase(find(allv(V), CV[0]));
		V.erase(find(allv(V), CV[1]));

		if('L' == A[1]) {
			AnsV.eb(CV[0]);
			AnsV.eb(CV[1]);
			solve(V, 2);
		} else {
			AnsV.eb(CV[1]);
			AnsV.eb(CV[0]);
			solve(V, 2);
		}
	}

	for(int v : AnsV) printf("%d ", v);
	puts("");
	return 0;
}