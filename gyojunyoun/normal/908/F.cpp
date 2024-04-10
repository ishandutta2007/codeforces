#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
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
typedef double ld;
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

const int MAXN = 300005;

vector<int> A, B, C;

ll Ans;
int N;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		int x; char c; scanf("%d %c", &x, &c);
		if('R' == c) A.pb(x);
		if('B' == c) B.pb(x);
		if('G' == c) C.pb(x);
	}
	if(C.empty()) {
		if(!A.empty()) Ans += A.back() - A[0];
		if(!B.empty()) Ans += B.back() - B[0];
		printf("%lld\n", Ans);
		return 0;
	}

	{
		if(!A.empty() && C.back() < A.back()) {
			Ans += A.back() - C.back();
			for(; !A.empty() && C.back() < A.back(); A.pop_back());
		}
		if(!B.empty() && C.back() < B.back()) {
			Ans += B.back() - C.back();
			for(; !B.empty() && C.back() < B.back(); B.pop_back());
		}
		if(!A.empty() && A[0] < C[0]) {
			Ans += C[0] - A[0];
			for(revv(A); !A.empty() && A.back() < C[0]; A.pop_back());
			revv(A);
		}
		if(!B.empty() && B[0] < C[0]) {
			Ans += C[0] - B[0];
			for(revv(B); !B.empty() && B.back() < C[0]; B.pop_back());
			revv(B);
		}
	}

	for(int i = 1, ai = 0, bi = 0; i < sz(C); i++) {
		vector<int> AA, BB;
		int amx = 0, bmx = 0, l = C[i] - C[i-1];
		for(; ai < sz(A) && A[ai] < C[i]; ai++) AA.pb(A[ai]);
		for(; bi < sz(B) && B[bi] < C[i]; bi++) BB.pb(B[bi]);
		if(AA.empty() && BB.empty()) {
			Ans += l;
			continue;
		}
		if(AA.empty()) amx = l;
		else {
			upmax(amx, AA[0] - C[i-1]);
			upmax(amx, C[i] - AA.back());
			for(int j = 1; j < sz(AA); j++) upmax(amx, AA[j] - AA[j-1]);
		}
		if(BB.empty()) bmx = l;
		else {
			upmax(bmx, BB[0] - C[i-1]);
			upmax(bmx, C[i] - BB.back());
			for(int j = 1; j < sz(BB); j++) upmax(bmx, BB[j] - BB[j-1]);
		}
		Ans += l*2 + min(0ll, (ll)l-amx-bmx);
	}
	printf("%lld\n", Ans);
	return 0;
}