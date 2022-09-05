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

ll x[nax], y[nax];
ll K(ll a) { return a * a; }
ll d(int i, int j) {
	return K(x[i]-x[j]) + K(y[i]-y[j]);
}

bool cmp(int i, int j) {
	return d(i,1) < d(j,1);
}

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%lld%lld", &x[i], &y[i]);
	vi w;
	FOR(i,2,n) w.pb(i);
	sort(w.begin(), w.end(), cmp);
	FOR(i,2,n) {
		x[i]-=x[1];
		y[i]-=y[1];
	}
	int i = w[0];
	for(int j : w) {
		ll tmp = x[i]*y[j]-y[i]*x[j];
		if(tmp != 0) {
			printf("%d %d %d\n", 1, i, j);
			return 0;
		}
	}
	assert(false);
	return 0;
}