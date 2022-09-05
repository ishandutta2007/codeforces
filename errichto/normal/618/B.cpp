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
const int nax = 55;

int t[nax][nax];
bool used[nax];
int inv[nax];

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) RI(j, n) {
		scanf("%d", &t[i][j]);
		if(t[i][j] == 0) t[i][j] = inf;
	}
	RI(val, n) {
		pii best = mp(-1,-1);
		RI(maybe, n) if(!used[maybe]) {
			int c = 0;
			RI(i, n) REP(_, 2) {
				if(t[maybe][i] == val) ++c;
				else if(t[maybe][i] != inf) c = -inf;
				swap(t[maybe][i], t[i][maybe]);
			}
			maxi(best, mp(c, maybe));
		}
		assert(best.st >= 0 && best.nd >= 0);
		int on = best.nd;
		used[on] = true;
		RI(i, n) t[i][on] = t[on][i] = inf;
		inv[on] = val;
	}
	RI(i, n) printf("%d ", inv[i]);
	puts("");
				
	return 0;
}