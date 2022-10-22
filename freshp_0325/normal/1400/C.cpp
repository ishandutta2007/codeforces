#include<bits/stdc++.h>
using namespace std;
char s[100005],k[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int x;
		scanf("%d",&x);
		for(int i=1;i<=n;++i)	k[i]='0';
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='1')
			{
				int p=i-x,q=i+x;
				bool flag=false;
				if(p>=1)
				{
					int pp=i-x-x;
					if(pp>=1)
					{
						if(s[pp]=='1')	flag=true,k[p]='1';
					}
					else	flag=true,k[p]='1';
				}
				if(q<=n)
				{
					int qq=i+x+x;
					if(qq<=n)
					{
						if(s[qq]=='1')	flag=true,k[q]='1';
					}
					else	flag=true,k[q]='1';
				}
				if(!flag)
				{
					puts("-1");
					goto fail;
				}
			}
		}
		for(int i=1;i<=n;++i)	putchar(k[i]);
		puts("");
		fail:;
	}
	return 0;
}