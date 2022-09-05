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
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", sl);
	FOR(i,0,1000) {
		int pom = n - a * i;
		if(pom >= 0 && pom % b == 0) {
			printf("%d\n", i + pom / b);
			int w = 0;
			REP(_, i) {
				REP(__, a) {
					printf("%c", sl[w]);
					++w;
				}
				puts("");
			}
			REP(_, pom / b) {
				REP(__, b) {
					printf("%c", sl[w]);
					++w;
				}
				puts("");
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}