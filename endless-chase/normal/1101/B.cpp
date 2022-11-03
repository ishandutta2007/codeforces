#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
char s[555555];
int n,l,r,ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	l=r=-1;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='[')
		{
			for (int j=i+1;j<n;j++)
			{
				if (s[j]==':') 
				{
					l=j;
					break;
				}
			}
			break;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		if (s[i]==']')
		{
			for (int j=i-1;j>=0;j--)
			{
				if (s[j]==':') 
				{
					r=j;
					break;
				}
			}
			break;
		}
	}
	if (!~l || !~r || l>=r) 
	{
		printf("-1\n");
		return 0;
	}
	ans=4;
	for (int i=l+1;i<r;i++)
	{
		if (s[i]=='|') ans++;
	}
	printf("%d\n",ans);
	return Accepted;
}