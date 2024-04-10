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
const int inf = 1e9 + 1375;
const int nax = 150;

int orig[nax], dest[nax], lim[nax];
bool sure[nax];
const int K = 50;

struct Matrix {
	ll t[nax][3];
	Matrix(){ REP(i, nax) REP(j, 3) t[i][j] = 0; }
	Matrix operator * (const Matrix & b) const {
		ll t2[nax][3];
		REP(i, nax) REP(j, 3) t2[i][j] = 0;
		REP(i, nax) REP(j, 3) REP(k, K)
			if(b.t[i][j] & (1LL << k))
				t2[j*K+k][i/K] |= (1LL << (i%K));
		Matrix res;
		REP(i, nax) REP(k, nax) {
			bool ok = false;
			REP(j, 3) if(t[i][j] & t2[k][j]) ok = true;
			if(ok)
				res.t[i][k/K] |= (1LL << (k%K));
		}
		return res;
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, m) {
		scanf("%d%d%d", &orig[i], &dest[i], &lim[i]);
		orig[i]--;
		dest[i]--;
	}
	int prv = 0;
	sure[0] = true;
	while(true) {
		int nxt = inf;
		REP(i, m) if(lim[i] > prv) mini(nxt, lim[i]);
		int diff = nxt - prv;
		Matrix res;
		REP(i, n) res.t[i][i/K] |= (1LL << (i%K));
		Matrix a;
		REP(i, m) if(lim[i] < nxt)
			a.t[orig[i]][dest[i]/K] |= (1LL << (dest[i]%K));
		a.t[n-1][(n-1)/K] |= (1LL << ((n-1)%K));
		Matrix a0 = a;
		while(diff) {
			if(diff % 2) res = res * a;
			a = a * a;
			diff /= 2;
		}
		ll ple[3];
		REP(i, 3) ple[i] = 0;
		REP(i, n) if(sure[i]) REP(j, 3)
			ple[j] |= res.t[i][j];
		if(ple[(n-1)/K] & (1LL << ((n-1)%K))) {
			//puts("ta");
			a = a0;
			int memo = prv;
			while(true) {
				//printf("%lld\n", a.t[1][0]);
				++prv;
				REP(i, n) if(sure[i] && (a.t[i][(n-1)/K] & (1LL << ((n-1)%K)))) {
					printf("%d\n", prv);
					return 0;
				}
				if(prv > memo + n + 155) {
					puts("Impossible");
					return 0;
				}
				a = a * a0;
			}
		}
		bool ok = false;
		REP(i, n) sure[i] = (ple[i/K] & (1LL << (i%K)));
		REP(i, n) ok |= sure[i];
		if(!ok) {
			puts("Impossible");
			return 0;
		}
		prv = nxt;
	}
	return 0;
}