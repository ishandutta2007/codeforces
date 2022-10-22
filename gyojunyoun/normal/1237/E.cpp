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

const int MOD = 998244353;
const int MAXN = 1000055;

ll pw(ll n, ll k) {
	ll r = 1; for(; k; k >>= 1) {
		if(k&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

ll DF[MAXN], IDF[MAXN];

ll com(int a, int b) {
	if(b < 0 || a < b) return 0;
	return DF[a] * IDF[b] % MOD * IDF[a-b] % MOD;
}

int RS, RD;
int N, K, LC;
int OddC, EvenC;

bitset<MAXN> col;
ll Ans;

vector<int> OV;

bool isLeaf(int i) { return K-LC+1 <= i && i <= K; }
pii f(int i) { // same, diff
	if(i*2 > K) {
		OV.eb(i);
		return {1, 0};
	}
	if(i*2+1 > K) {
		OV.eb(i);
		return {1, 1};
	}

	col[i*2] = !col[i];
	col[i*2+1] = col[i];
	pii l = f(i*2);
	OV.eb(i);
	pii r = f(i*2+1);
	return {1 + r.first + l.second, r.second + l.first};
}

int main() {
	DF[0] = 1;
	for(int i = 1; i < MAXN; i++) DF[i] = DF[i-1] * i % MOD;
	IDF[MAXN-1] = inv(DF[MAXN-1]);
	for(int i = MAXN-2; 0 <= i; i--) IDF[i] = IDF[i+1] * (i+1) % MOD;

	cin >> N;
	if(1 == N) {
		puts("1");
		exit(0);
	}
	if(2 == N) {
		puts("1");
		exit(0);
	}
	if(3 == N && 0) {
		puts("0");
		exit(0);
	}
	K = 1; for(; K*2+1 <= N; K = K*2+1);
	LC = (K+1) / 2;

	col[1] = true;
	tie(RS, RD) = f(1);

	EvenC = N/2; OddC = N - EvenC;

	int leftcnt = N - K;

	// even root
	{
		bool failed = false;
		int oc = 0, ec = 0;
		for(int oi = 0, i, num = 1; oi < K; oi++) {
			i = OV[oi];
			bool sc = (num&1) ? false : true;
			if(sc == col[i]) {
				num++;
				continue;
			}
			num += 2;
			if(isLeaf(i)) {
				if(col[i]) {
					oc++;
				} else {
					ec++;
				}
			} else {
				if(!oi) {
					failed = true;
					break;
				}
				if(!isLeaf(OV[oi-1])) {
					failed = true;
					break;
				}
				int pi = OV[oi-1];
				if(col[i]) {
					if(col[pi]) {
						failed = true;
						break;
					}
					oc++;
				} else {
					if(!col[pi]) {
						failed = true;
						break;
					}
					ec++;
				}
			}
		}

		if(!failed && ec+RS == EvenC && oc+RD == OddC) {
			Ans++;
		}
	}


	// odd root
	{
		bool failed = false;
		int oc = 0, ec = 0;
		for(int oi = 0, i, num = 1; oi < K; oi++) {
			i = OV[oi];
			bool sc = (num&1) ? true : false;
			if(sc == col[i]) {
				num++;
				continue;
			}
			num += 2;
			if(isLeaf(i)) {
				if(col[i]) {
					ec++;
				} else {
					oc++;
				}
			} else {
				if(!oi) {
					failed = true;
					break;
				}
				if(!isLeaf(OV[oi-1])) {
					failed = true;
					break;
				}
				int pi = OV[oi-1];
				if(col[i]) {
					if(col[pi]) {
						failed = true;
						break;
					}
					ec++;
				} else {
					if(!col[pi]) {
						failed = true;
						break;
					}
					oc++;
				}
			}
		}

		if(!failed && ec+RD == EvenC && oc+RS == OddC) {
			Ans++;
		}
	}

	cout << Ans << endl;
	return 0;
}