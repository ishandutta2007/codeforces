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

long long value[2][1000005];
int sum[2][1005];

int main(){
	int n, m, k, p;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j){
			int a;
			scanf("%d", &a);
			sum[0][i] += a;
			sum[1][j] += a;
		}
	sort(sum[0], sum[0]+n);
	sort(sum[1], sum[1]+m);
	priority_queue<long long> pq[2];
	for(int i=0; i < 2; ++i){
		int l=i?m:n;
		for(int j=0; j < l; ++j)
			pq[i].push(sum[i][j]);
		value[i][0]=0;
		for(int j=0; j <= k+3; ++j){
			value[i][j+1]=value[i][j]+pq[i].top();
			pq[i].push(pq[i].top()-(p*(m*n))/l);
			pq[i].pop();
		}
	}
	long long ans=-999999999999999999LL;
	for(int i=0; i <= k; ++i){
		long long b=i;
		b *= (k-i);
		b *= p;
		ans=max(ans, value[0][i]+value[1][k-i]-b);
	}
	printf("%I64d\n", ans);
	return 0;
}