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
#define fi first
#define se second
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

vector<string> A[105], B[105], C[105];

char Ans[105];

char StartKey;

int N;

int main() {
	scanf("%d", &N);

	if(1 == N) {
		printf("? 1 1\n");
		fflush(stdout);

		char tmp[5];
		scanf(" %s", tmp);

		printf("! %s\n", tmp);
		fflush(stdout);
		exit(0);
	}

	printf("? 1 %d\n", N);
	fflush(stdout);

	for(int t = N * (N+1) / 2; t--;) {
		char str[105];
		scanf(" %s", str);
		string S(str);
		A[sz(S)].eb(S);
	}

	printf("? 1 1\n");
	fflush(stdout);

	{
		char str[55];
		scanf(" %s", str);
		StartKey = str[0];
		B[1].eb(string(str));
	}

	printf("? 2 %d\n", N);
	fflush(stdout);

	for(int t = (N-1) * N / 2; t--;) {
		char str[105];
		scanf(" %s", str);
		string S(str);
		C[sz(S)].eb(S);
	}


	Ans[1] = StartKey;

	multiset<string> G[105];
	for(int i = 2; i <= N; i++) {
		for(auto &v : A[i]) sorv(v);
		for(auto &v : C[i]) sorv(v);
		for(auto &v : A[i]) G[i].insert(v);
		for(auto &v : C[i]) G[i].erase(G[i].find(v));
	}

	for(int i = 2; i <= N; i++) {
		int cnt[55] = {0, };
		for(int j = 1; j < i; j++) cnt[Ans[j]-'a']++;
		auto S = *G[i].begin();
		for(int j = 0; j < i; j++) cnt[S[j]-'a']--;

		for(int j = 'a'; j <= 'z'; j++) {
			if(cnt[j-'a']) Ans[i] = j;
		}
	}

	printf("! %s\n", Ans+1);
	return 0;
}