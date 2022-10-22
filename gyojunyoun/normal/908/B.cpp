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
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char A[55][55];
char S[105];
int T[4];
int H, W, Sy, Sx, Ey, Ex;
int Ans;

int main() {
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; i++) scanf(" %s", A[i]+1);
	for(int i = 1; i <= H; i++) {
		for(int j = 1; j <= W; j++) {
			if('S' == A[i][j]) {
				A[i][j] = '.';
				Sy = i; Sx = j;
			}
			if('E' == A[i][j]) {
				A[i][j] = '.';
				Ey = i; Ex = j;
			}
		}
	}
	scanf(" %s", S);
	iota(T, T+4, 0);
	do {
		int y = Sy, x = Sx;
		bool flag = false;
		for(int t = 0; S[t]; t++) {
			const int dir = T[S[t] - '0'];
			y += dy[dir]; x += dx[dir];
			if('.' != A[y][x]) {
				flag = true; break;
			}
			if(y == Ey && x == Ex) break;
		}
		if(Ey != y || Ex != x) flag = true;
		Ans += !flag;
	} while(next_permutation(T, T+4));
	printf("%d\n", Ans);
	return 0;
}