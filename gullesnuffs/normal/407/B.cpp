#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define MOD 1000000007
using namespace std;

int p[1005];
long long cost[1005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", p+i);
		cost[i]=2;
		for(int j=p[i]-1; j < i; ++j)
			cost[i] += cost[j];
		cost[i]%=MOD;
	}
	long long ans=0;
	for(int i=0; i < n; ++i)
		ans += cost[i];
	ans %= MOD;
	printf("%I64d\n", ans);
	return 0;
}