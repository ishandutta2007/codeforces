#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,cnt,crt,cp,flg;
char s[222222];
int main()
{
	scanf("%d",&test);
	while(test--) 
	{
		scanf("%d",&n);
		scanf("%s",s);
		cnt=0;crt=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0') crt++;
		}
		if (crt&1)
		{
			printf("NO\n");
			continue;
		}
		cp=0;
		int tt=(n-crt)/2;
		flg=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0')
			{
				if (crt&1) cnt++;
				else cnt--;
				crt++;
			}
			else
			{
				if (cp<tt) cnt++;
				else cnt--;
				cp++;
			}
			if (cnt<0)
			{
				flg=1;
				break;
			}
		}
		if (!flg)
		{
			printf("YES\n");
			cp=0;
			for (int i=0;i<n;i++)
			{
				if (s[i]=='0')
				{
					if (crt&1) printf("(");
					else printf(")");
					crt++;
				}
				else
				{
					if (cp<tt) printf("(");
					else printf(")");
					cp++;
				}
			}
			printf("\n");
			cp=0;
			for (int i=0;i<n;i++)
			{
				if (s[i]=='0')
				{
					if (crt&1) printf(")");
					else printf("(");
					crt++;
				}
				else
				{
					if (cp<tt) printf("(");
					else printf(")");
					cp++;
				}
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return Accepted;
}