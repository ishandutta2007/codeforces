#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,ans,pos,lst,arr[1111],cnt;
char s[1111];
bool can;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++)
	{
		lst=i;
		for (int j=0;j<n;j++)
		{
			if (s[j]=='(') lst--;
			if (!lst) 
			{
				pos=j;
				break;
			}
		}
		if (lst) continue;
		lst=i;
		for (int j=n-1;j>=0;j--)
		{
			if (s[j]==')') lst--;
			if (!lst)
			{
				if (j>pos) ans=i;
				break;
			}
		}
	}
	if (!ans)
	{
		printf("0\n");
		return 0;
	}
	printf("1\n");
	printf("%d\n",(ans<<1));
	lst=ans;
	for (int i=0;i<n;i++)
	{
		if (!lst) break;
		if (s[i]=='(')
		{
			lst--;
			printf("%d ",i+1);
		}
	}
	lst=ans;
	for (int i=n-1;i>=0;i--)
	{
		if (!lst) break;
		if (s[i]==')')
		{
			lst--;
			arr[++cnt]=i+1;
		}
	}
	for (int i=cnt;i>=1;i--) printf("%d ",arr[i]);
	printf("\n");
	return Accepted;
}