#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m;
char s[N],t[N];
void sol()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=i;j<=n;j++)
		{
			if(s[j]!=t[p+1])
				break;
			p++;
			if(p==m)
			{
				puts("YES");
				return;
			}
			int q=p;
			for(int k=j-1;k;k--)
			{
				if(s[k]!=t[q+1])
					break;
				q++;
				if(q==m)
				{
					puts("YES");
					return;
				}
			}
		}
	}
	puts("NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}