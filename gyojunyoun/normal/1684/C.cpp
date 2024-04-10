#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
ll pw(ll n) { return n*n; }


int A[200055], B[200055];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	
	int T;
	cin >> T;

	while(T--) {
		int H, W;
		cin >> H >> W;

		int na = -1, nb = -1;
		bool failed = false;

		vector<vector<int>> G(H), SG(H);

		while(H--) {
			for(int i = 0; i < W; i++) {
				cin >> A[i];
				B[i] = A[i];
			}
			sort(B, B+W);

			{
				vector<int> T(W);
				for(int i = W; i--;) T[i] = A[i];
				G[H] = T;

				for(int i = W; i--;) T[i] = B[i];
				SG[H] = T;
			}


			vector<int> V;
			for(int i = 0; i < W; i++) {
				if(A[i] != B[i]) {
					V.eb(i);
				}
			}

			if(sz(V) > 2) {
				failed = true;
				continue;
			}

			if(V.empty()) {
				if(na < 0) continue;

				if(A[na] != A[nb]) {
					failed = true;
					continue;
				}

				continue;
			}

			if(1 == sz(V)) {
				failed = true;
				continue;
			}

			int a = V[0], b = V[1];

			if(na < 0) {
				na = a;
				nb = b;
			} else {
				if(a != na || b != nb) {
					failed = true;
					continue;
				}
			}
		}

		if(na < 0) na = nb = 0;

		H = sz(G);

		for(int i = H; i--;) {
			vector<int> V = G[i];
			swap(V[na], V[nb]);
			if(V != SG[i]) {
				failed = true;
				break;
			}
		}

		if(failed) cout << "-1\n";
		else cout << na+1 << ' ' << nb+1 << '\n';
	}

	return 0;
}