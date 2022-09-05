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

char sl[nax];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	int ans = 0;
	REP(i, n) FOR(j,i,n-1) {
		int x = 0;
		int y = 0;
		FOR(k,i,j) {
			char z = sl[k];
			if(z == 'U') ++y;
			else if(z == 'D') --y;
			else if(z == 'R') ++x;
			else if(z == 'L') --x;
		}
		if(x == 0 && y == 0) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}