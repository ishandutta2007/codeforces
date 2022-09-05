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
const int mod = 1e9 + 7;

int pw(int a, int b) {
	int r = 1;
	while(b) {
		if(b%2) r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

bool vis[nax];

int main() {
	int p, k;
	scanf("%d%d", &p, &k);
	if(k == 0) {
		printf("%d\n", pw(p, p - 1));
		return 0;
	}
	if(k == 1) {
		printf("%d\n", pw(p, p));
		return 0;
	}
	int ans = 1;
	RI(i, p - 1) if(!vis[i]) {
		//int c = 0;
		do {
			//++c;
			vis[i] = true;
			i = (ll) i * k % p;
		} while(!vis[i]);
		ans = (ll) ans * p % mod;
	}
	printf("%d\n", ans);
	return 0;
}