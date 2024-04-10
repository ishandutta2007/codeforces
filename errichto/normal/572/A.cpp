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
	int n[2];
	REP(i,2) scanf("%d", &n[i]);
	int k[2];
	REP(i,2) scanf("%d", &k[i]);
	int g;
	RI(i, n[0]) {
		int a;
		scanf("%d", &a);
		if(i == k[0]) g = a;
	}
	RI(i, n[1]) {
		int a;
		scanf("%d", &a);
		if(n[1]-i+1 == k[1]) {
			if(g < a) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}