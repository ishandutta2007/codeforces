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

const int MAXN = 200055;
const int SQRN = 300;

int MP[MAXN*(SQRN+5)];

int S[MAXN];

char A[MAXN];

ll Ans;
int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> A;
	N = strlen(A);
	for(int i = 1; i <= N; i++)
		S[i] = S[i-1] + (A[i-1]&15);
	
	if(!S[N]) {
		puts("0");
		exit(0);
	}

	for(int k = 1; k <= SQRN; k++) {
		for(int i = 0; i <= N; i++) {
			int &t = MP[k * S[i] - i + N];
			Ans += t;
			t++;
		}
		for(int i = 0; i <= N; i++)
			MP[k * S[i] - i + N] = 0;
	}

	vector<pii> V;
	V.eb(0, 0);
	for(int i = 1; i <= N; i++) {
		if(S[i] == S[V.back().fi]) V.back().se = i;
		else V.eb(i, i);
	}
	int n = sz(V), mxc = N/SQRN + 1;

	for(int vi = 0; vi < n; vi++) {
		for(int i = V[vi].fi, e = V[vi].se; i <= e; i++) {
			for(int nvi = vi+1, kl, kr; nvi <= vi+mxc && nvi < n; nvi++)
				Ans += max(0, (V[nvi].se-i)/(nvi-vi) - max(SQRN+1, (V[nvi].fi-i+nvi-vi-1)/(nvi-vi)) + 1);
		}
	}

	cout << Ans << endl;
	return 0;
}