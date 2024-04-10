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

vector<pii> G[105][105];
bitset<105> vis[105], col[105];

int N;

bool isok(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void dfs(int y, int x) {
	vis[y][x] = true;
	for(auto &v : G[y][x]) {
		int ny, nx; tie(ny, nx) = v;
		if(vis[ny][nx]) continue;
		col[ny][nx] = !col[y][x];
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		for(int di : {1, -1}) for(int dj : {2, -2}) {
			int ni = i+di, nj = j+dj;
			if(isok(ni, nj)) G[i][j].eb(ni, nj);
		}
		for(int di : {2, -2}) for(int dj : {1, -1}) {
			int ni = i+di, nj = j+dj;
			if(isok(ni, nj)) G[i][j].eb(ni, nj);
		}
	}

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		if(!vis[i][j]) dfs(i, j);
	

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			putchar(col[i][j] ? 'B' : 'W');
		}
		putchar('\n');
	}
	return 0;
}