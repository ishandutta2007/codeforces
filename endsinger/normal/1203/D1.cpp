#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N],t[N];
int main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int p=1;
			for(int i=1;i<=n;i++)
			{
				if(i==l) i=r+1;
				if(s[i]==t[p])
					p++;
				if(p==m+1)
					break; 
			}
			if(p==m+1)
				ans=max(ans,r-l+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}