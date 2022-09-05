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

int wizyta[nax], ucieczka[nax], confi[nax];
int memo[nax];

int main() {
	int n;
	scanf("%d", &n);
	vi res;
	RI(i, n) {
		scanf("%d%d%d", &wizyta[i], &ucieczka[i], &confi[i]);
	}
	RI(i, n) {
		if(confi[i] >= 0) {
			res.pb(i);
			int tmp = wizyta[i];
			FOR(j,i+1,n) memo[j] = confi[j];
			FOR(j,i+1,n) if(confi[j] >= 0) {
				confi[j] -= tmp;
				
				--tmp;
				if(tmp == 0) break;
			}
			FOR(j,i+1,n) if(confi[j] < 0 && memo[j] >= 0)
				FOR(k,j+1,n) if(confi[k] >= 0) confi[k] -= ucieczka[j];
		}
	}
			
		
	printf("%d\n", sz(res));
	for(int a : res) printf("%d ", a);
	puts("");
	return 0;
}