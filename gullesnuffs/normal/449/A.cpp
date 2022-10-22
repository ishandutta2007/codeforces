#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	long long K=k, N=n, M=m;
	if(k >= n+m-1)
		puts("-1");
	else{
		long long ans=0;
		for(long long i=0; i*i <= 10*K+50; ++i){
			if(i > k)
				continue;
			long long a=n/(i+1);
			long long b=m/(k-i+1);
			ans=max(ans, a*b);
			a=m/(i+1);
			b=n/(k-i+1);
			ans=max(ans, a*b);

			long long fit=n/(i+1)-1;
			if(fit <= k && fit >= 0)ans=max(ans, (N/(fit+1))*(m/(k-fit+1)));
			fit=m/(i+1)-1;
			if(fit <= k && fit >= 0)ans=max(ans, (M/(fit+1))*(n/(k-fit+1)));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}