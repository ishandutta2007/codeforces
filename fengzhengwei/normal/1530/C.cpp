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
const int xx=100005;
int a[xx],b[xx],n;
bool check(int x)
{
	int rem=(x+n)/4;
	ll sa;
	if(rem>n)sa=(x+n-rem)*100;
	else sa=x*100+a[n]-a[rem];
	ll sb;
	if(rem>x)sb=b[n]-b[rem-x];
	else sb=b[n];
	return sa>=sb;
}
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)a[i]+=a[i-1],b[i]+=b[i-1];
		int l=0,r=4*n,ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}