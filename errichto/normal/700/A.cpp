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
	int n, total, v1, v2, k;
	scanf("%d%d%d%d%d", &n, &total, &v1, &v2, &k);
	if(k == n) {
		printf("%.10lf\n", (double) total / v2);
		return 0;
	}
	int kursy = (n + k - 1) / k;
	double g1, g2;
	g1 = g2 = 0;
	g1 = v1;
	g2 = v2;
	double tajm = 1;
	REP(_, kursy - 1) {
		double x = (g2 - g1) * v1 / (v1 + v2);
		// double y = (g2 - g1) * v2 / (v1 + v2);
		double dif = x / v1;
		tajm += dif;
		g1 += dif * v1;
		g2 += dif * v1; // on foot
		dif = (g2 - g1) / (double) (v2 - v1);
		tajm += dif;
		g1 += dif * v1;
		g2 += dif * v1;
	}
	printf("%.10lf\n", tajm * (double) total / g2);
	return 0;
}