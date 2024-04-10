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



int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int x = 1; true; ++x) {
		int both = x / 6;
		int a = x / 2 - both;
		int b = x / 3 - both;
		if(n <= a + both && m <= b + both && n + m <= a + b + both) {
			printf("%d\n", x);
			return 0;
		}
	}
	return 0;
}