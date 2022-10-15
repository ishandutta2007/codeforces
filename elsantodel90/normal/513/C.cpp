#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

typedef long long tint;

int n, l[8], r[8];

double dp[6][6][10010][6];
double calc(int pos, int gana, int maxi, int equals) {
	if(equals < 0) return 0.0;
	if(pos == n) {
		return (equals == 0 ? 1.0 : 0.0);
	}
	//cout << pos << " " << gana << " " << maxi << " " << equals << endl;

	double& ret = dp[pos][gana][maxi][equals];
	if(ret != -1.0) return ret;

	if(pos == gana) {
		return (ret = calc(pos+1, gana, maxi, equals));
	}

	ret = 0.0;
	double menorCaso;
	if(l[pos] > maxi) return (ret = 0);
	else if (r[pos] < maxi) menorCaso = r[pos]-l[pos]+1;
	else menorCaso = maxi-l[pos];

	ret += calc(pos+1, gana, maxi, equals) *  menorCaso / (double(r[pos]-l[pos]+1));

	if(l[pos] <= maxi && maxi <= r[pos]) {
		ret += calc(pos+1, gana, maxi, equals-1) *  1.0 / (double(r[pos]-l[pos]+1));
	}

	return ret;
}

int main(){
#ifdef ACMTUYO
	freopen("c.in", "r", stdin);
#endif

	cin >> n;
	forn(i, n) cin >> l[i] >> r[i];

	forn(i, 6) forn(j, 6) forn(k, 10010) forn(t, 6) dp[i][j][k][t] = -1.0;
	double ret = 0.0;

	forn(gana, n) forn(maxi, 10010) forsn(equals, 1, n) {
		if(maxi <= r[gana]) {
			double caso = calc(0, gana, maxi, equals);
			double casoMayor;
			if (l[gana] > maxi) casoMayor = r[gana]-l[gana]+1;
			else casoMayor = r[gana]-maxi;

			ret += ((double) maxi) * caso * casoMayor / (double(r[gana]-l[gana]+1));
			if(l[gana] <= maxi && maxi <= r[gana])
				ret += ((double) maxi) * caso * (1.0 / (double(r[gana]-l[gana]+1))) * 1.0 / (double(equals+1));
		}
	}

	printf("%.9f\n", ret);

	return 0;
}