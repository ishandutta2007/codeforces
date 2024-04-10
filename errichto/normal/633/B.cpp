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

int f(int i) {
	int r = 0;
	while(i) {
		r += i / 5;
		i /= 5;
	}
	return r;
}

int main() {
	int m;
	scanf("%d", &m);
	vi w;
	RI(i,1000 * 1000) if(f(i) == m) w.pb(i);
	printf("%d\n", sz(w));
	for(int a : w) printf("%d ", a);
	puts("");
	return 0;
}