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
int n;
int main(){
	int T=read();
	while(T--)
	{
		ll n,a,b;
		n=read();
		a=read();
		b=read();
		if(a==1)
		{
			if((n-1)%b==0)puts("Yes");
			else puts("No");
			continue;
		}
		ll now=1;
		int vis=0;
		while(now<=n)
		{
			if((n-now)%b==0)
			{
				puts("Yes");
				vis=1;
				break;
			}
			now*=a;
		}
		if(!vis)puts("No");
	}
	
	return 0;
}