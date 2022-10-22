#include<bits/stdc++.h>
using namespace std;
char s[505],t[1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s %s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				if(j-i+1>m)	break;
				int st=m-(j-i+1);
				int k=j-st;
				if(k<0)	continue;
				int pos=1;
				for(int l=i;l<=j;++l)
				if(t[pos]!=s[l])	goto fail;
				else	++pos;
				for(int l=j-1;l>=k;--l)
				if(t[pos]!=s[l])	goto fail;
				else	++pos;
				puts("YES");
				goto reset;
				fail:;
			}
		}
		puts("NO");reset:;
	}
	return 0;
}