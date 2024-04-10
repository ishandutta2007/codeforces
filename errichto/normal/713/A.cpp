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

int t[1 << 18];

int main() {
	int z;
	scanf("%d", &z);
	while(z--) {
		char type[3], sl[20];
		scanf("%s", type);
		scanf("%s", sl);
		int m = 0;
		int d = strlen(sl);
		REP(i, 18) {
			if(i < 18 - d) {}
			else {
				int j = i - (18 - d);
				if((sl[j] - '0') % 2) m ^= (1 << i);
			}
		}
		if(type[0] == '+') ++t[m];
		else if(type[0] == '-') --t[m];
		else printf("%d\n", t[m]);
	}
	return 0;
}