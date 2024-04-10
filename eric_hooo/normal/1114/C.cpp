#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pii;

int main(){
	long long n, b;
	scanf("%I64d%I64d", &n, &b);
	vector <pii> v;
	for (long long i = 2; i * i <= b; i++){
		if (b % i) continue;
		v.push_back(mp(i, 0));
		while (b % i == 0) b /= i, v.back().se++;
	}
	if (b > 1) v.push_back(mp(b, 1));
	long long ans = 2e18;
	for (int i = 0; i < v.size(); i++){
		long long tot = 0;
		long long p = v[i].fi;
		long long now = n;
		while (now){
			tot += now / p;
			now /= p;
		}
		ans = min(ans, tot / v[i].se);
	}
	printf("%I64d\n", ans);
	return 0;
}