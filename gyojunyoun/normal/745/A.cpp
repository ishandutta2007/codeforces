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
#define MAXN (55)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

vector<vector<char>> V;
char str[MAXN];
int N;

int main() {
	scanf(" %s", str);
	N = (int)strlen(str);
	for(int i = 0; i < N; i++) {
		V.pb(vector<char>());
		vector<char> &Q = V.back();
		for(int j = i; j < N; j++) Q.pb(str[j]);
		for(int j = 0; j < i; j++) Q.pb(str[j]);
	}
	sorv(V); univ(V);
	printf("%d\n", sz(V));
	return 0;
}