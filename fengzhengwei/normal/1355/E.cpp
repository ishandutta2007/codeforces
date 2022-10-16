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
int n,a,r,m;
const int xx=1e5+5;
int h[xx];
ll get(int x)
{
	ll a1=0,a2=0;
	for(int i=1;i<=n;i++)if(h[i]>=x)a2+=h[i]-x;
	for(int i=1;i<=n;i++)if(h[i]<x)a1+=x-h[i];
	if(a1<a2)return a1*m+(a2-a1)*r;
	if(a1>=a2)return a2*m+(a1-a2)*a;
}
int main(){
	n=read();a=read();
	r=read();m=read();
	m=min(m,a+r);
	for(int i=1;i<=n;i++)h[i]=read();
	int l=0,r=1e9;
	while(l+2<r)
	{
		int mid=l+r>>1;
		if(get(mid)<get(mid+1))r=mid+1;
		else l=mid;
	}
	ll res=1e18;
	for(int i=l;i<=r;i++)res=min(res,get(i));
	cout<<res<<"\n";
	return 0;
}