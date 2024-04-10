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
#define fi first
#define se second
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

const int MAXN = 1055;

char A[MAXN];

int N, M;

void run() {
	cin >> N >> M;
	cin >> A;

	vector<int> V;
	for(int i = 0; i < N; i++) {
		if('1' == A[i]) V.eb(i);
	}

	if(V.empty()) {
		for(int i = 0; i < N; i++)
			cout << '0';
		cout << '\n';
		return;
	}

	int pv = 0, n = sz(V);
	for(int i = 0; i < N; i++) {
		if(pv+1 < n && V[pv+1] < i) pv++;

		if(0 == pv && i <= V[pv]) {
			if(V[pv] - i <= M) cout << '1';
			else cout << '0';
		} else if(pv+1 == n) {
			if(i - V[pv] <= M) cout << '1';
			else cout << '0';
		} else {
			int l = i - V[pv];
			int r = V[pv+1] - i;

			if(i == V[pv]) cout << '1';
			else if(min(l, r) <= M && l != r) cout << '1';
			else cout << '0';
		}
	}
	cout << '\n';
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;
	for(int ti = 1; ti <= T; ti++) run();

	return 0;
}