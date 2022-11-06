#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define L 1000010
#define M 1010
#define P 170
#define mod 1000000007
using namespace std;
int pr[M],tot;
bool p[M];
int ksm(int a,int b=mod-2)
{
	int r=1;
	for(;b;b>>=1)
	{
		if(b&1) r=1ll*r*a%mod;
		a=1ll*a*a%mod;
	}
	return r;
}
void pre_work(int n)
{
	for(int i=2;i<=n;i++)
	if(!p[i]) 
	{
		pr[++tot]=i;
		for(int j=i*2;j<=n;j+=i) p[j]=true;
	}
}
int a[N],bl[N];
int tf[N][P];
struct node{
	int l,r,id;
	bool operator <(const node a)const{return bl[l]==bl[a.l]?r<a.r:bl[l]<bl[a.l];}
}q[N];
int cnt[L],iv[L];
int ans[N],res=1;
void add(int x)
{
	if(x==1) return;
	if(cnt[x]) res=1ll*res*x%mod;
	else res=1ll*res*(x-1)%mod;
//	if(!res) throw;
	cnt[x]++;
}
void del(int x)
{
	if(x==1) return;
	cnt[x]--;
	if(cnt[x]) res=1ll*res*iv[x]%mod;
	else res=1ll*res*iv[x-1]%mod;
//	if(!res) throw;
}
int main()
{
	pre_work(M-1);
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<L;i++) iv[i]=ksm(i);
	for(int i=1;i<=tot;i++) tf[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		memcpy(tf[i],tf[i-1],sizeof(tf[i]));
		for(int j=1;j<=tot && a[i]>=pr[j];j++)
		while(a[i]%pr[j]==0) tf[i][j]=1ll*tf[i][j]*pr[j]%mod,a[i]/=pr[j];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	const int B=558;
	for(int i=1;i<=n;i++) bl[i]=i/B;
	sort(q+1,q+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]);
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		ans[q[i].id]=res;
		int s1=1;
		for(int j=1;j<=tot;j++)
		if(tf[q[i].r][j]!=tf[q[i].l-1][j])
			ans[q[i].id]=1ll*ans[q[i].id]*(pr[j]-1)%mod*tf[q[i].r][j]%mod,s1=1ll*s1*tf[q[i].l-1][j]%mod*pr[j]%mod;
		ans[q[i].id]=1ll*ans[q[i].id]*ksm(s1)%mod;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}