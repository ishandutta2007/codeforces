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
using namespace std;

int a[100005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i <= n; ++i){
		scanf("%d", a+i);
	}
	long long ans=999999999;
	for(int i=1; i <= n; ++i){
		long long sum=0;
		for(int j=i+1; j <= n && j <= i+1005; ++j){
			sum += a[j];
			ans=min(ans, (j-i)*(j-i)+sum*sum);	
		}
	}
	printf("%I64d\n", ans);
	return 0;
}