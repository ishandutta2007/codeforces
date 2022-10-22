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

inline void ask(int s, int e, vector<string> V[]) {
	printf("? %d %d\n", s, e);
	fflush(stdout);

	char str[555];
	for(int l = e-s+1, t = l*(l+1)/2; t--;) {
		scanf(" %s", str);
		string S(str);
		sorv(S);
		V[sz(S)].eb(S);
	}
	for(int i = 105; i--;) sorv(V[i]);
}

vector<string> A[105], B[105], C[105];

char Ans[105];

int N, M;

int main() {
	scanf("%d", &N);

	ask(1, N, A);
	if(1 == N) {
		printf("! %c\n", A[1][0][0]);
		fflush(stdout);
		exit(0);
	}

	M = N/2 + 1;

	ask(1, M, B); ask(2, M, C);

	for(int i = 0; i < M; i++) {
		multiset<string> PQ;
		for(auto &v : B[i+1]) PQ.insert(v);
		for(auto &v : C[i+1]) PQ.erase(PQ.find(v));

		string S = *PQ.begin();
		int cnt[26] = {0, };
		for(int j = 0; j <= i; j++) cnt[S[j]-'a']++;
		for(int j = i; j--;) cnt[Ans[j]-'a']--;
		for(int j = 26; j--;) if(cnt[j]) Ans[i] = 'a'+j;
	}

	for(int i = M, ni; i < N; i++) {
		ni = N-i-1;
		if(Ans[i] && Ans[ni]) continue;

		int cnt[26] = {0, };
		for(auto &v : A[ni+1]) for(char c : v) cnt[c-'a']++;
		for(auto &v : A[ni]) for(char c : v) cnt[c-'a']--;
		for(int j = ni+1; j < i; j++) cnt[Ans[j]-'a']--;

		char ca = 0, cb = 0;
		for(int j = 26; j--;) {
			if(cnt[j]) {
				(ca ? cb : ca) = 'a'+j;
				cnt[j]--;
			}
			if(cnt[j]) {
				(ca ? cb : ca) = 'a'+j;
				cnt[j]--;
			}
		}
		Ans[i] = ca + cb - Ans[ni];
	}

	printf("! %s\n", Ans);
	fflush(stdout);
	return 0;
}