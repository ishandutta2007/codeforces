#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

bool is[nax];

int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) {
		puts("0");
		return 0;
	}
	FOR(i,2,n) is[i] = true;
	FOR(i,2,n) if(is[i]) for(int j = 2 * i; j <= n; j += i) is[j] = false;
	vi w;
	FOR(i,2,n) if(is[i]) {
		for(int j = i; j <= n; j *= i) w.pb(j);
	}
	printf("%d\n", sz(w));
	for(int a : w) printf("%d ", a);
	puts("");
	return 0;
}