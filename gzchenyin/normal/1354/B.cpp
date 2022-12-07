#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,l,r,cnt[4];
char s[200005];
bool check()
{
	if(cnt[1]==0 || cnt[2]==0 || cnt[3]==0) return false;
	return true;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),ans=1e9;
		r=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=len;i++)
		{
			if(i!=1) cnt[s[i-1]-'0']--;
			while(!check() && r!=len+1)
			{
				r++;
				if(r!=len+1) cnt[s[r]-'0']++;
			}
//			printf("%d %d %d %d %d\n",i,r,cnt[1],cnt[2],cnt[3]);
			if(r==len+1) break;
			ans=min(ans,r-i+1);
		}
		if(ans==1e9) printf("0\n");
		else printf("%d\n",ans);
	}
}