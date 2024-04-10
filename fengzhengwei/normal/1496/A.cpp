#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int n,m;
const int xx=505;
char s[xx];
signed main(){
	T=read();
	while(T--)
	{
		n=read();
		m=read();
		scanf("%s",s+1);
		if(m==0)
		{
			puts("YES");
			continue;
		}
		int ss=1;
		for(int i=1;i<=m;i++)
		{
			if(s[i]!=s[n-i+1])
			{
				ss=0;
				break;
			}
		}
		if(!ss)puts("NO");
		else 
		{
			if(n==m*2)puts("NO");
			else 
			{
				puts("YES");
			}
		}
	}
	return 0;
}