#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,ans;
char s[333333];
bool flg,cur;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		flg=0;cur=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='<') cur=1;
		}
		if (!cur) flg=1;
		cur=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='>') cur=1;
		}
		if (!cur) flg=1;
		if (flg) printf("%d\n",n);
		else
		{
			ans=0;
			for (int i=0;i<n;i++)
			{
				if (s[i]=='-' || s[(i+n-1)%n]=='-') ans++;
			}
			printf("%d\n",ans);
		}
	}
	return Accepted;
}