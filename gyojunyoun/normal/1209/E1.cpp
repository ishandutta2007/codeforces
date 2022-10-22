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

vector<int> A[105];
int B[4][105];

int T, H, W, Ans;

void run() {
	cin >> H >> W;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> B[i][j];
	for(int i = 0; i < W; i++) {
		A[i].clear();
		for(int j = 0; j < H; j++)
			A[i].eb(B[j][i]);
		rotate(A[i].begin(), max_element(allv(A[i])), A[i].end());
	}
	sort(A, A+W); reverse(A, A+W);
	Ans = 0;

	if(1 == H) {
		cout << A[0][0] << endl;
		return;
	}
	if(2 == H) {
		Ans = A[0][0] + A[0][1];
		if(1 < W) upmax(Ans, A[0][0] + A[1][0]);
		cout << Ans << endl;
		return;
	}
	if(3 == H) {
		Ans = A[0][0] + A[0][1] + A[0][2];
		for(int i = 1; i < W; i++) {
			for(int j = 0; j < H; j++) {
				int sum = 0;
				for(int k = 0; k < H; k++) {
					sum += max(A[0][k], A[i][(j+k)%H]);
				}
				upmax(Ans, sum);
			}
		}
		if(2 < W) upmax(Ans, A[0][0] + A[1][0] + A[2][0]);
		cout << Ans << endl;
		return;
	}
	Ans = A[0][0] + A[0][1] + A[0][2] + A[0][3];
	for(int i = 1; i < W; i++) {
		for(int j = 0; j < H; j++) {
			int sum = 0;
			for(int k = 0; k < H; k++) {
				sum += max(A[0][k], A[i][(j+k)%H]);
			}
			upmax(Ans, sum);
		}
	}
	for(int i = 1; i < W; i++) for(int j = i+1; j < W; j++) {
		for(int a = 0; a < H; a++) for(int b = 0; b < H; b++) {
			int sum = 0;
			for(int k = 0; k < H; k++) {
				sum += max({A[0][k], A[i][(k+a)%H], A[j][(k+b)%H]});
			}
			upmax(Ans, sum);
		}
	}
	if(3 < W) upmax(Ans, A[0][0] + A[1][0] + A[2][0] + A[3][0]);
	cout << Ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for(; T--;) run();
	return 0;
}