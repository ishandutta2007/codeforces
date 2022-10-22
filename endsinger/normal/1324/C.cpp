#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='L')
			{
				int j=i;
				while(s[j]=='L')
					j++;
				mx=max(mx,j-i);
				i=j-1;
			}
		}
		printf("%d\n",mx+1);
	}
	return 0;
}