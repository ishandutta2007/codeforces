#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
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

ll t[nax];
map<ll, int> m;
ll r[nax];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	RI(i,n) scanf("%lld", &t[i]);
	
	RI(i, n) {
		if(t[i] % k == 0) r[i] = m[t[i]/k];
		m[t[i]]++;
	}
	m.clear();
	ll w = 0;
	FORD(i,n,1) {
		r[i] *= m[t[i]*k];
		w += r[i];
		m[t[i]]++;
	}
	printf("%lld\n", w);
	return 0;
}