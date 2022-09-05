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

int t[nax], a[nax], b[nax];

int main()
{
	int n;
	scanf("%d", &n);
	RI(i,n) scanf("%d", &t[i]);
	RI(i,n) {
		a[i] = 2*inf;
		b[i] = 0;
		vi w;
		if(i != 1) w.pb(1);
		if(i != 1) w.pb(i-1);
		if(i != n) {
			w.pb(n);
			w.pb(i+1);
		}
		for(int k : w) {
			maxi(b[i], abs(t[i] - t[k]));
			mini(a[i], abs(t[i] - t[k]));
		}
		printf("%d %d\n", a[i], b[i]);
	}
	return 0;
}