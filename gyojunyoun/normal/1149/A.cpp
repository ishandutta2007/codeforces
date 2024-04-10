#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }
void fg(vector<pii> G[], int a, int b, int c) { G[a].pb({b, c}); G[b].pb({a, c}); }

const int MAXX = 400055;

bitset<MAXX> isnp;

vector<int> AnsV; int Ans = -1;
vector<int> V; int Cnt;

int N, A, B, C, D;

int main() {
	isnp[0] = isnp[1] = true;
	for(int i = 4; i < MAXX; i += 2) isnp[i] = true;
	for(int i = 3; i*i < MAXX; i += 2) if(!isnp[i])
		for(int j = i*i; j < MAXX; j += i) isnp[j] = true;

	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; i++) {
		int c;
		cin >> c;
		if(1 == c) A++;
		else B++;
	}

	if(1 == N) {
		if(1 == B) puts("2");
		else puts("1");
		return 0;
	}

	if(2 == N) {
		if(2 == B) puts("2 2");
		else if(1 == B) puts("2 1");
		else puts("1 1");
		return 0;
	}

	for(int a = 0; a < 3; a++) for(int b = 0; b < 3; b++) {
		if(A < a || B < b || a + b > 4) continue;

		Cnt = 0;
		V.clear();

		vector<int> O;
		for(int i = 0; i < a; i++) O.eb(1);
		for(int i = 0; i < b; i++) O.eb(2);
		do {
			V = O;

			C = A - a;
			D = B - b;

			for(int i = 0; i < D; i++) V.eb(2);
			for(int i = 0; i < C; i++) V.eb(1);

			int sum = 0;
			Cnt = 0;
			for(int v : V) {
				sum += v;
				if(!isnp[sum]) Cnt++;
			}

			if(Ans < Cnt) {
				Ans = Cnt;
				AnsV = V;
			}
		} while(next_permutation(allv(O)));
	}

	for(int v : AnsV) printf("%d ", v);
	puts("");
	return 0;
}