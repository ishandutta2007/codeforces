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
int n;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
const int xx=1e5+5;
int a[xx];
int pre[xx];
int nex[xx];
int sum[xx<<2];
void change(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		if(!y)sum[k]=0;
		else sum[k]=l;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y);
	else change(k<<1|1,mid+1,r,x,y);
	if(sum[k<<1])sum[k]=sum[k<<1];
	else sum[k]=sum[k<<1|1];
}
int ask(int k,int l,int r,int x,int y)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return sum[k];
	int mid=l+r>>1;
	int s=0;
	if(x<=mid)s=ask(k<<1,l,mid,x,y);
	if(mid<y)
	{
		int a=ask(k<<1|1,mid+1,r,x,y);
		if(!s)s=a;
	}
	return s;
}
void build(int k,int l,int r)
{
	sum[k]=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
signed main(){
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),pre[i]=i-1;
		pre[1]=n;
		for(int i=1;i<=n;i++)nex[i]=i+1;
		nex[n]=1;
		build(1,1,n);
		for(int i=1;i<=n;i++)
		if(gcd(a[i],a[pre[i]])==1)
		{
			change(1,1,n,i,1);
//			cout<<i<<"\n";
		}
		int now=2;
		vector<int>v;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			if(ask(1,1,n,1,n)==0)break;
			now=ask(1,1,n,now,n);
			if(!now){i--;now=1;continue;}
			v.push_back(now);
			change(1,1,n,now,0);
			pre[nex[now]]=pre[now];
			nex[pre[now]]=nex[now];
			if(gcd(a[nex[now]],a[now])==1)change(1,1,n,nex[now],0);
			if(gcd(a[nex[now]],a[pre[now]])==1)
			{
//				cout<<nex[now]<<" "<<pre[now]<<"sss \n";
				change(1,1,n,nex[now],1);
			}
			now=nex[now];
			now=nex[now];
		}
		cout<<v.size()<<" ";
		for(int i=0;i<v.size();i++)cout<<v[i]<<" \n"[i==v.size()-1];
	}
	return 0;
}