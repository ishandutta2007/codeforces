#include<bits/stdc++.h>
#define ll long long
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
int n;
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		ll res=0;
		for(int i=1;i<=n;i++)res+=read();
		if(n==1){puts("0");continue;}
		if(res%n==0){puts("0");continue;}
		cout<<(res%n)*(n-res%n)<<'\n';
	}
	return 0;
}