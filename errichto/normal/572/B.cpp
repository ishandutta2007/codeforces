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
const int nax = 1e5 + 5;

int a[nax], b[nax];

int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	while(n--) {
		char sl[2];
		int price, volume;
		scanf("%s%d%d", sl, &price, &volume);
		if(sl[0] == 'B') b[price] += volume;
		else a[price] += volume;
	}
	vi w;
	int c = 0;
	REP(i,nax) if(c < s && a[i]) {
		w.pb(i);
		//printf("S %d %d\n", i, a[i]);
		++c;
	}
	reverse(w.begin(), w.end());
	for(int i : w) printf("S %d %d\n", i, a[i]);
	c = 0;
	FORD(i,nax-1,0) if(c < s && b[i]) {
		printf("B %d %d\n", i, b[i]);
		++c;
	}
	return 0;
}