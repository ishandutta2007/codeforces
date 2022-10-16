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
const int xx=1e5+5;
int n,m,a[xx],q[xx],l,r;
ll f[xx];
signed main(){
	n=read(),m=read();
	ll sm=0;
	for(int i=1;i<=n;i++)a[i]=read(),sm+=a[i];
	l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=r&&q[l]<=i-m)l++;
		while(l<=r&&a[q[r]]>=a[i])r--;
		q[++r]=i;
		if(i>=m)f[i]=max(f[i-1],f[i-m]+a[q[l]]);
	}
	cout<<sm-f[n]<<"\n";
    return 0;
}