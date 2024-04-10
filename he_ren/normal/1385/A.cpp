#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void solve(void)
{
	int a[4];
	for(int i=1; i<=3; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+3+1);
	reverse(a+1,a+3+1);
	
	if(a[1] != a[2]) printf("NO\n");
	else
	{
		printf("YES\n");
		printf("%d %d %d\n",a[1],a[3],1);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}