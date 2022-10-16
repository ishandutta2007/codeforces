#include<bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int main(){
	T=read();
	while(T--)
	{
		int n,m;
		n=read();
		m=read();
		ll now=0;
		for(int i=0;i<n;i++)
		{
			cout<<(i^now)<<'\n';
			fflush(stdout);
			int r=read();
			if(r==1)break;
			now^=(i^now);
		}
	}
	return 0;
}