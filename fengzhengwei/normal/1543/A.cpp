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
int main(){
	int T=read();
	while(T--)
	{
		ll a,b;
		a=read();
		b=read();
		if(a<b)swap(a,b);
		if(a==b)
		{
			puts("0 0");
			continue;
		}
		else cout<<a-b<<" "<<min(a%(a-b),(a-b)-(a%(a-b)))<<"\n";
	}
	return 0;
}