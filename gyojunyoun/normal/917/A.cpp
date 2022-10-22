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

const int MAXN = 5005;

int B[MAXN][MAXN];
char A[MAXN];

int Ans, N;

int main() {
	scanf(" %s", A+1); N = (int)strlen(A+1);
	for(int i = 1; A[i]; i++) {
		int l = 0, a = 0, b = 0;
		for(int j = i; A[j]; j++) {
			l++;
			if('?' == A[j]) a++;
			else b += (')' == A[j] ? -1 : 1);
			if(a+b < 0) break;
			if(l&1) continue;
			if('(' == A[j]) continue;
			if(abs(b) > a) continue;
			B[i][j] = 1;
		}
	}
	reverse(A+1, A+N+1);
	for(int i = 1; A[i]; i++) if('?' != A[i]) A[i] = ')' == A[i] ? '(' : ')';
	for(int i = 1; A[i]; i++) {
		int l = 0, a = 0, b = 0;
		for(int j = i; A[j]; j++) {
			l++;
			if('?' == A[j]) a++;
			else b += (')' == A[j] ? -1 : 1);
			if(a+b < 0) break;
			if(l&1) continue;
			if('(' == A[j]) continue;
			if(abs(b) > a) continue;
			B[N-j+1][N-i+1] |= 2;
		}
	}
	for(int i = 1; A[i]; i++) for(int j = i+1; A[j]; j++) Ans += 3 == B[i][j];
	printf("%d\n", Ans);
	return 0;
}