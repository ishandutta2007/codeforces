#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
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
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define MAXN (105)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

vector<char> V, Q;
char str[MAXN], tmp[MAXN];
int A, B;

int main() {
	scanf("%d. %s", &A, tmp);
	int s = 0;
	for(; tmp[s]; s++) {
		if('e' == tmp[s]) break;
		str[s] = tmp[s];
	}
	s++;
	for(; tmp[s]; s++) {
		B = B*10 + (tmp[s] - '0');
	}
	V.pb(A + '0');
	for(int i = 0; i < B; i++) {
		if(str[i]) V.pb(str[i]);
		else V.pb('0');
	}
	for(int i = B; str[i]; i++) Q.pb(str[i]);
	revv(V); while(!V.empty() && V.back() == '0') V.pop_back();
	revv(V);
	while(!Q.empty() && Q.back() == '0') Q.pop_back();
	if(V.empty()) {
		printf("0");
	} else {
		for(char v : V) putchar(v);
	}
	if(Q.empty()) { puts(""); return 0; }
	printf(".");
	for(char v : Q) putchar(v);
	puts("");
	return 0;
}