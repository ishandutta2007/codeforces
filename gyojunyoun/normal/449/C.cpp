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

bitset<MAXN> isnp;

vector<pii> Ans;
bitset<MAXN> chk;

int N;

int main() {
	isnp[0] = isnp[1] = true;
	for(int i = 4; i < MAXN; i += 2) isnp[i] = true;
	for(int i = 3; i*i < MAXN; i += 2) if(!isnp[i])
		for(int j = i*i; j < MAXN; j += i+i) isnp[j] = true;
	
	cin >> N;

	for(int p = 3; p*2 <= N; p += 2) if(!isnp[p]) {
		vector<int> V;
		for(int i = p; i <= N; i += p+p)
			if(!chk[i]) V.eb(i);
		for(int i = p+p; i <= N; i += p+p)
			if(!chk[i]) V.eb(i);
		for(int i = 1, n = sz(V); i < n; i += 2) {
			chk[V[i-1]] = chk[V[i]] = true;
			Ans.eb(V[i-1], V[i]);
		}
	}

	vector<int> V;
	for(int i = 2; i <= N; i += 2)
		if(!chk[i]) V.eb(i);
	for(int i = 1, n = sz(V); i < n; i += 2)
		Ans.eb(V[i-1], V[i]);
	
	cout << sz(Ans) << '\n';
	for(auto &v : Ans) cout << v.first << ' ' << v.second << '\n';
	return 0;
}