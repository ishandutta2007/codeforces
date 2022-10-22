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

int x[1000005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		scanf("%d", x+i);
	sort(x, x+n);
	int p=x[n/2];
	long long ans=0;
	for(int i=0; i < n/2; i += m){
		ans += p-x[i];
	}
	for(int i=n-1; i > n/2; i -= m){
		ans += x[i]-p;
	}
	ans *= 2;
	printf("%I64d\n", ans);
	return 0;
}