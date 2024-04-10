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

bitset<1<<20> isPA, isPB;
int DB[1<<20];

vector<int> G[40];
bitset<40> A[40];
int nei[40], overnei[20];

int NoNei, CN;

ll Ans;
int N, M, K;

ll solveRet;
void solve() {
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < K; j++)
			if(A[i][j]) nei[i] |= 1<<j;
	}
	for(int i = K; i < N; i++) {
		for(int j = K; j < N; j++)
			if(A[i][j]) nei[i] |= 1<<(j-K);
	}

	for(int key = 1<<K; key--;) {
		bool flag = false;
		for(int i = 0; i < K; i++) if((key & (1<<i)) && (key & nei[i])) {
			flag = true;
			break;
		}
		if(!flag) isPA[key] = true;
	}
	for(int key = 1<<(N-K); key--;) {
		bool flag = false;
		for(int i = K; i < N; i++) if((key & (1<<(i-K))) && (key & nei[i])) {
			flag = true;
			break;
		}
		if(!flag) isPB[key] = true;
	}

	for(int i = 0; i < K; i++) {
		for(int j = K; j < N; j++)
			if(A[i][j]) overnei[i] |= 1<<(j-K);
	}

	for(int key = 1<<(N-K); key--;) if(isPB[key]) DB[key]++;
	for(int i = 0; i < N-K; i++) {
		for(int key = 0, e = 1<<(N-K); key < e; key++) if(key & (1<<i)) {
			DB[key] += DB[key ^ (1<<i)];
		}
	}

	for(int key = 1<<K, masterkey = (1<<(N-K))-1; key--;) if(isPA[key]) {
		int overkey = 0;
		for(int i = 0; i < K; i++) if(key & (1<<i))
			overkey |= overnei[i];
		overkey ^= masterkey;
		solveRet += DB[overkey];
	}
}

bitset<40> BiColor, BiChk;
bool BiFailed = false;
void Bidfs(int i) {
	BiChk[i] = true;
	for(int v : G[i]) {
		if(BiChk[v]) {
			if(BiColor[i] == BiColor[v]) {
				BiFailed = true;
			}
			continue;
		}
		BiColor[v] = !BiColor[i];
		Bidfs(v);
	}
}
void solveBipar() {
	for(int i = 0; i < N; i++) if(!BiChk[i]) {
		Bidfs(i);
	}
}

bitset<40> CNchk;
void CNdfs(int i) {
	CNchk[i] = true;
	for(int v : G[i]) if(!CNchk[v])
		CNdfs(v);
}
void countCN() {
	for(int i = 0; i < N; i++) if(!CNchk[i]) {
		CN++;
		CNdfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for(int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		A[a][b] = A[b][a] = true;
		fg(G, a, b);
	}
	if(M < 3) {
		puts("0");
		exit(0);
	}

	// 2, 3
	for(int i = 0; i < N; i++) if(G[i].empty()) NoNei++;
	Ans += (1ll << NoNei) << 1;

	// 4
	countCN();
	solveBipar();
	if(!BiFailed) Ans += 1ll << CN;

	// 5
	Ans -= 1ll << CN;

	// 6, 7
	K = N>>1;
	solve();
	Ans -= solveRet << 1;

	// 8
	Ans += 1ll << N;

	cout << Ans << endl;
	return 0;
}