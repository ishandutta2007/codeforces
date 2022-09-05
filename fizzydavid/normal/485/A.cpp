#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long LL;
bool use[maxn];
int m,a;
int main()
{
	scanf("%d%d",&a,&m);
	for(int i=1;i<=m*2;i++)
	{
		if(a==0)
		{
			puts("Yes");
			return 0;
		}
		if(use[a])
		{
			puts("No");
			return 0;
		}
		use[a]=true;
		a=a*2%m;
	}
	return 0;
}