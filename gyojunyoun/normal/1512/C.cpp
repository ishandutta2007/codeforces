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

char A[200055];

int B, C, N;

void run() {
	cin >> B >> C >> A;

	N = strlen(A);

	if(B+C != N) {
		puts("-1");
		return;
	}

	if(N&1) {
		if('?' == A[N/2]) {
			if(B&1) {
				A[N/2] = '0';
			} else if(C&1) {
				A[N/2] = '1';
			} else {
				puts("-1");
				return;
			}
		}
	}

	for(int s = 0, e = N-1; s < e; s++, e--) {
		if('?' == A[s] && '?' == A[e]) continue;
		if('?' == A[s]) A[s] = A[e];
		if('?' == A[e]) A[e] = A[s];
		if(A[s] != A[e]) {
			puts("-1");
			return;
		}
	}

	for(int i = 0; i < N; i++) {
		if('0' == A[i]) B--;
		else if('1' == A[i]) C--;
	}

	if(B < 0 || C < 0 || (B&1) || (C&1)) {
		puts("-1");
		return;
	}

	for(int s = 0, e = N-1; s < e; s++, e--) {
		if('?' == A[s]) {
			if(B) {
				B -= 2;
				A[s] = A[e] = '0';
			} else {
				C -= 2;
				A[s] = A[e] = '1';
			}
		}
	}

	for(int i = 0; i < N; i++)
		putchar(A[i]);
	putchar('\n');
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	for(; T--;) run();

	return 0;
}