#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1e6+5;
int n,m,a[xx];
int vs[xx],prim[xx];
void pre()
{
	int cnt=0;
	vs[1]=1;
	for(int i=2;i<xx;i++)
	{
		if(!vs[i])
			prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			vs[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}

ll solve(vector<int>&v)
{
	ll ans=0;
	int len=v.size();
	for(int i=0;i<len;i++)
	{
		int l=i,r=i;
		if(vs[v[i]])continue;
		while(l!=0&&v[l-1]==1)l--;
		while(r+1!=len&&v[r+1]==1)r++;
		ans+=1ll*(r-i+1)*(i-l+1);
		ans--;
	}
	return ans;
}
signed main(){
	pre();
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			vector<int>v;
			for(int j=i;j<=n;j+=m)
				v.push_back(a[j]);
			ans+=solve(v);
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}