#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,num;
char s[222222];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);num=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='A')
			{
				num++;
			}
			else if (!num) num++;
			else num--;
		}
		printf("%d\n",num);
	}
	return Accepted;
}