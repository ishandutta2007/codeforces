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

const int MAXX = 1000000;

int A[105];

int CU, CV;
int T, N;

void run() {
	cin >> N >> CU >> CV;
	for(int i = 1; i <= N; i++) cin >> A[i];

	int Ans = CV * 2;

	for(int i = 2; i < N; i++) {
		int s = max(A[i-1]-1, A[i+1]-1);
		int e = min(A[i-1]+1, A[i+1]+1);

		if(A[i] < s || e < A[i]) {
			Ans = 0;
			break;
		}

		if(A[i-1] != A[i] || A[i+1] != A[i]) upmin(Ans, CU);
		else upmin(Ans, CU + CV);

		if(s == A[i] || e == A[i]) upmin(Ans, CV);
	}

	if(A[1] != A[2]) upmin(Ans, CU);
	else upmin(Ans, CU + CV);

	if(A[1] < A[2]-1 || A[2]+1 < A[1]) Ans = 0;
	else if(A[1] == A[2]+1 || (A[1] == A[2]-1 && 0 < A[1]-1)) upmin(Ans, CV);

	if(A[N] != A[N-1]) upmin(Ans, CU);
	else upmin(Ans, CU + CV);

	if(A[N] < A[N-1]-1 || A[N-1]+1 < A[N]) Ans = 0;
	else if(A[N] == A[N-1]-1 || (A[N] == A[N-1]+1 && MAXX >= A[N]+1)) upmin(Ans, CV);

	cout << Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T; for(; T--;) run();
	return 0;
}