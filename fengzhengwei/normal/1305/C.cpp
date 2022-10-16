#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int xx=2e5+5;
int n,m,a[xx];
int main(){
	n=read(),m=read();
	if(n>=m+1){puts("0");return 0;}
	for(int i=1;i<=n;i++)a[i]=read();
	ll ans=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans*=abs(a[i]-a[j]),ans%=m;
	cout<<ans<<"\n";
	return 0;
}