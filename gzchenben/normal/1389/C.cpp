#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,cnt[1005];
char s[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans1=1000000000,ans2=1000000000;
		for(char tx='0';tx<='9';tx++)
		{
			for(char ty='0';ty<='9';ty++)
			{
				int now=1,tmp=0;
				for(int i=1;i<=n;i++)
				{
					if(now==1 && s[i]==tx)
					{
						tmp++;
						now=2;
					} 
					else if(now==2 && s[i]==ty)
					{
						tmp++;
						now=1;
					}
				}
				tmp-=tmp%2;
				ans1=min(ans1,n-tmp);
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) cnt[s[i]]++;
		for(char tx='0';tx<='9';tx++) 
		{
			int tmp=cnt[tx];
			tmp-=(1-(tmp%2));
			ans2=min(ans2,n-tmp);
		}
		printf("%d\n",min(ans1,ans2));
	}
}