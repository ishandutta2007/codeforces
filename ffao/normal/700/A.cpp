#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n,k,v1,v2,l;
int trips;

bool check(double mid) {
	// dist / v2 + (l-dist) / v1 = mid
	// (v1-v2)dist + v2*l = mid*v1*v2
	// (v1-v2)dist = mid - v2*l

	double dist_time = (mid*v1 - l) / (v1-v2);
	
	//if (dist_time < 0) return true;

	double back_time = dist_time * (v2-v1) / (v2+v1);
	
	double tot_time = dist_time * trips + back_time * (trips-1);
	return tot_time <= mid;
}

void solve() {
	scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);

	trips = (n+k-1)/k;

	double st = 0, ed = l/(double)v1;
	
	REP(it, 100) {
		double mid = (st+ed)/2;
		if (check(mid)) ed = mid;
		else st = mid;
	} 

	printf("%.15f\n", (st+ed)/2);
}


int main() {
    solve();
}