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

long long max(long long a, long long b){
	return a>b?a:b;
}

int main(){
	long long n, m, k;
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	long long Min=-1, Max=99999999999999999LL;
	while(Max-Min > 1){
		long long mid=(Min+Max)/2;
		long long larger=0;
		for(int i=1; i <= n; ++i){
			larger += max(0, m-mid/i);
		}
		if(larger > n*m-k)
			Min=mid;
		else
			Max=mid;
	}
	printf("%I64d\n", Max);
	return 0;
}