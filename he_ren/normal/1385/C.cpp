#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[n+1] = 0;
	
	int cur = n;
	while(cur>=1 && a[cur] >= a[cur+1]) --cur;
	while(cur>=1 && a[cur] <= a[cur+1]) --cur;
	printf("%d\n",cur);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}