#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
ll mul(ll a,ll b,ll mod){return a%=mod,a+=mod,a%=mod,b%=mod,b+=mod,b%=mod,(a*b-mod*(long long)((long double)a/mod*b)+mod)%mod;}
const int xx=2e5+5;
int K[xx];
struct pr
{
	ll x,y;
	pr(){}pr(ll a,ll b):x(a),y(b){}
};
vector<pr>v[xx];
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	ll X=y,Y=x-(a/b)*y;
	x=X,y=Y;
}
pr merge(pr a,pr b)//mod 
{
	if(a.x==-1||b.x==-1)return pr(-1,-1);
	ll d=gcd(a.y,b.y);
	if(abs(a.x-b.x)%d)return pr(-1,-1);
	ll X,Y;
	exgcd(a.y,b.y,X,Y);
//	assert(a.y&&b.y);
	X=mul(X,(b.x-a.x)/d,b.y/d);
	X%=b.y/d,X+=b.y/d,X%=b.y/d;
//	cout<<d<<" "<<a.x<<" ss "<<b.x<<" "<<a.y<<" "<<b.y<<"\n";
	return pr((mul(X,a.y,b.y/d*a.y)+a.x)%(b.y/d*a.y),b.y/d*a.y);
}
pr f[xx][21];
int lg[xx];
pr ask(int l,int r)
{
	int k=lg[r-l+1];
//	cout<<l<<" "<<r<<"\n";
//	cout<<l<<" "<<k<<" "<<r-(1<<k)+1<<" "<<k<<"\n";
	return merge(f[l][k],f[r-(1<<k)+1][k]);
}
signed main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		K[i]=read();
		for(int j=0;j<K[i];j++)
		{
			int x=read();
			v[x].push_back(pr(i,j));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int sz=v[i].size();
		for(int j=1;j<=sz;j++)
			f[j][0]=pr(v[i][j-1].y,K[v[i][j-1].x]);
		for(int k=1;k<=20;k++)
		{
			for(int j=1;j<=sz;j++)
			{
				if(j+(1<<k)<=sz+1)
				f[j][k]=merge(f[j][k-1],f[j+(1<<k-1)][k-1]);
			}
		}
//		if(i==3)cout<<f[2][1].x<<" "<<f[2][1].y<<" ss "<<"\n";
		int ans=0,r=1;
		for(int l=1;l<=sz;l++)
		{
			r=max(r,l);
			while((r+1)<=sz&&v[i][r+1-1].x==v[i][r-1].x+1&&ask(l,r+1).x!=-1)r++;
//		if(i==3)cout<<l<<" "<<r<<" "<<ask(l,r+1).x<<"!!\n";
			ans=max(ans,r-l+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}