#include<bits/stdc++.h>
#define ll long long
#define dd double
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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int n,m,k;
vector<ll>v[4];
ll sum[4][xx];
int cr[xx],c[xx];
struct DS
{
	multiset<ll>s1,s2;
	ll sum=0;
	void in(ll a){s1.insert(a);}
	void tok(int k)//k 
	{
		while(s2.size()>k)sum-=*--s2.end(),s1.insert(*--s2.end()),s2.erase(--s2.end());
		while(s2.size()<k)s2.insert(*s1.begin()),sum+=*s1.begin(),s1.erase(s1.begin());
		while(s2.size()&&*--s2.end()>*s1.begin())
		{
			// 
			s1.insert(*--s2.end()),sum-=*--s2.end(),s2.erase(--s2.end()),s2.insert(*s1.begin()),sum+=*s1.begin(),s1.erase(s1.begin());
		}
	}
}D;
signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)c[i]=read();
	int a=read();
	while(a--)cr[read()]++;
	a=read();
	while(a--)cr[read()]+=2;
	for(int i=1;i<=n;i++)v[cr[i]].push_back(c[i]);
	for(int i=0;i<4;i++)sort(v[i].begin(),v[i].end());
	if(k>m)puts("-1"),exit(0);
	multiset<ll>s;
	ll ans=1e18;
	for(int i=1;i<=2;i++)while(v[i].size()<n)v[i].push_back(1e12);
	for(int i=0;i<4;i++)
		for(int j=1;j<=v[i].size();j++)
		{
			if(v[i][j-1]>1e9)sum[i][j]=1e16;
			else sum[i][j]=v[i][j-1]+sum[i][j-1];
		}
	// 
	for(auto it:v[0])D.in(it);
	for(int i=k+1;i<=n;i++)D.in(v[1][i-1]);
	for(int i=k+1;i<=n;i++)D.in(v[2][i-1]);
	for(int i=0;i<=v[3].size();i++)
	{
		int mst=i+max(0,k-i)*2;
		if(mst<=m)
		{
			D.tok(m-mst);
//			cout<<m-mst<<" "<<D.sum<<" "<<mst<<" "<<i<<"!!\n";
			ans=min(ans,sum[3][i]+sum[2][max(0,k-i)]+sum[1][max(0,k-i)]+D.sum);
		}
		if(k-i>0)D.in(v[1][k-i-1]),D.in(v[2][k-i-1]);
	}
	if(ans>1e15)puts("-1");
	else cout<<ans<<"\n";
	pc('1',1);
	return 0;
}