#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define mod 1000000007
#define N 100010
using namespace std;
struct ques{int l,r,id; bool operator <(const ques a)const{return r<a.r;}}qs[N];
ll ksm(ll a,ll b)
{
	if(b==0) return 1;if(b==1) return a;
	ll q=ksm(a,b>>1);
	if(b&1) return q*q%mod*a%mod;
	return q*q%mod;
}
int fa[N],pre[N];
ll sum[N],f[N];
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
void merge(int x,int y)
{
	fa[x]=fa[y];
	pre[y]=pre[x];
	int len=x-pre[x];
	if((len>=30 && sum[y]>0) || (sum[x]+(sum[y]<<len)>mod)) sum[y]=mod;
	else sum[y]=sum[x]+(sum[y]<<len);
}
ll val[N],num[N],ans[N],_2[N];
ll get(int l,int r){return (val[l]-val[r+1]*_2[r-l+1]%mod+mod)%mod;}
void merge_until(int &u)
{
	while(pre[u] && sum[u]>=0) merge(pre[u],u);
	f[u]=(f[pre[u]]+get(pre[u]+1,u)*2%mod)%mod;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	_2[0]=1;
	for(int i=1;i<=n;i++) scanf("%lld",&num[i]), _2[i]=_2[i-1]*2%mod;
	for(int i=1;i<=q;i++) scanf("%d%d",&qs[i].l,&qs[i].r), qs[i].id=i;
	sort(qs+1,qs+q+1);
	for(int i=1;i<=n;i++) fa[i]=i, sum[i]=num[i], pre[i]=i-1;
	for(int i=n;i>=1;i--) val[i]=(val[i+1]*2%mod+num[i]+mod)%mod;
	int p=0;
	for(int i=1;i<=n;i++)
	{
		merge_until(i);
		while(qs[p+1].r==i)
		{
			p++;
			int u=find(qs[p].l);
			ans[qs[p].id]=(f[i]-f[u]+mod+get(qs[p].l,u))%mod;
		}
	}
	for(int i=1;i<=q;i++)
	printf("%lld\n",ans[i]);
	return 0;
}