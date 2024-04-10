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

const int MAXN = 1005;

void norm(pll &v) {
	ll g = gcd(abs(v.first), abs(v.second));
	if(g) {
		v.first /= g;
		v.second /= g;
	}
	if(v.first < 0 || (!v.first && v.second < 0)) {
		v.first = -v.first;
		v.second = -v.second;
	}
}

struct LNE {
	pll a, d;

	void norm() {
		::norm(d);
	}

	bool operator == (const LNE &t) const {
		if(d != t.d) return false;
		pll v = t.a - a;
		::norm(v);
		return v == d || (v * (-1)) == d;
	}

	bool operator < (const LNE &t) const {
		if(operator ==(t)) return false;
		if(d != t.d) return d < t.d;
		ll my = d.second * a.first - d.first * a.second;
		ll your = d.second * t.a.first - d.first * t.a.second;
		return my < your;
	}
};

map<pll, ll> MP;
set<LNE> PQ;

pll P[MAXN];

ll Ans;
int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> P[i].first >> P[i].second;

	for(int i = 1; i <= N; i++) for(int j = i+1; j <= N; j++) {
		if(P[i] == P[j]) continue;
		LNE l;
		l.a = P[i];
		l.d = P[j] - P[i];
		l.norm();

		PQ.insert(l);
	}

	for(auto &l : PQ) {
		MP[l.d]++;
	}

	Ans = ll(sz(PQ)) * (sz(PQ)-1) / 2;
	for(auto &v : MP) {
		Ans -= ll(v.second) * (v.second-1) / 2;
	}

	cout << Ans << endl;
	return 0;
}