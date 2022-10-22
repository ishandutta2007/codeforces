#include<bits/stdc++.h>
using namespace std;
int T,n,k;
char s[100005];
int cnt[27];
int main(){
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d %d",&n,&k);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;++i)	++cnt[s[i]-'a'];
		for(int i=0;i<=25;++i)	if(cnt[i]%k)	goto reset;
		puts(s+1);
		continue;
		reset:;
//		memset(cnt,0,sizeof cnt);
		for(int i=n;i;--i)
		{
			--cnt[s[i]-'a'];
			int sum=0;
			for(int j=0;j<=25;++j)	if(cnt[j]%k)	sum+=k-(cnt[j]%k);
			if(sum>=0)
			{
				for(int j=0;j<=25;++j)
				{
					if(j>s[i]-'a')
					{
						int tmp=sum,sp=cnt[j]%k;
						if(sp)	--tmp;
						else	tmp+=k-1;
						int len=n-i;
						if((len-tmp)%k==0 && len>=tmp)
						{
							for(int l=1;l<i;++l)	putchar(s[l]);
							++cnt[j];
							putchar('a'+j);
							for(int l=1;l<=len-tmp;++l)	putchar('a');
							for(int l=0;l<=25;++l)
							{
								while(cnt[l]%k)	putchar('a'+l),++cnt[l];
							}
							goto fuck;
						}
					}
				}
			}
		}
		puts("-1");
		continue;
		fuck:;
		puts("");
	}
	return 0;
}