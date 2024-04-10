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

int **A, **B, **C, **D;

int H, W, Ans = INF;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> H >> W;
	A = new int*[H];
	B = new int*[H];
	C = new int*[H];
	D = new int*[H];
	{
		char str[300005];
		for(int i = 0; i < H; i++) {
			A[i] = new int[W];
			B[i] = new int[W];
			C[i] = new int[W];
			D[i] = new int[W];
			cin >> str;
			for(int j = 0; j < W; j++) {
				if('A' == str[j]) A[i][j] = 0;
				else if('C' == str[j]) A[i][j] = 1;
				else if('G' == str[j]) A[i][j] = 2;
				else A[i][j] = 3;
			}
		}
	}

	int order[4] = {0, 1, 2, 3}, reo[4];
	do {
		for(int i = 0; i < 4; i++) reo[order[i]] = i;
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				B[i][j] = order[A[i][j]];

		int ret = 0;
		for(int i = 0; i < H; i++) {
			int mn = INF, sum = 0;
			for(int j = 0; j < W; j++) {
				int a = B[i][j], b = ((i&1) ? 0 : 2) | ((j&1) ? 0 : 1);
				if(a != b) sum++;
				C[i][j] = b;
			}
			mn = sum;
			sum = 0;
			for(int j = 0; j < W; j++) {
				int a = B[i][j], b = ((i&1) ? 0 : 2) | ((j&1) ? 1 : 0);
				if(a != b) sum++;
			}
			if(mn < sum) {
				ret += mn;
				continue;
			}
			ret += sum;
			for(int j = 0; j < W; j++) {
				int a = B[i][j], b = ((i&1) ? 0 : 2) | ((j&1) ? 1 : 0);
				if(a != b) sum++;
				C[i][j] = b;
			}
		}
		if(ret < Ans) {
			Ans = ret;
			for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
				D[i][j] = reo[C[i][j]];
		}
		ret = 0;

		for(int j = 0; j < W; j++) {
			int sum = 0, mn = INF;
			for(int i = 0; i < H; i++) {
				int a = B[i][j], b = ((i&1) ? 0 : 2) | ((j&1) ? 0 : 1);
				if(a != b) sum++;
				C[i][j] = b;
			}
			mn = sum; sum = 0;
			for(int i = 0; i < H; i++) {
				int a = B[i][j], b = ((i&1) ? 2 : 0) | ((j&1) ? 0 : 1);
				if(a != b) sum++;
			}
			if(mn < sum) {
				ret += mn; continue;
			}
			ret += sum;
			for(int i = 0; i < H; i++) {
				int a = B[i][j], b = ((i&1) ? 2 : 0) | ((j&1) ? 0 : 1);
				if(a != b) sum++;
				C[i][j] = b;
			}
		}
		if(ret < Ans) {
			Ans = ret;
			for(int i = 0; i < H; i++) for(int j = 0; j < W; j++)
				D[i][j] = reo[C[i][j]];
		}
	} while(next_permutation(order, order+4));


	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			putchar("ACGT"[D[i][j]]);
		}
		putchar('\n');
	}
	return 0;
}