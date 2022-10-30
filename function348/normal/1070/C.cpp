#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=5000001,M=200010;
int cnt[N];
LL mx[N],tag[N],t[N];
int n,m,k;
int l[M],r[M],p[M],c[M],id[M];
int cmp(int i,int j) { return p[i]<p[j];}
void build(int i,int l,int r)
{
	int mid=(l+r)>>1;
	t[i]=1LL*(r-l+1)*k;
	mx[i]=k;tag[i]=0;cnt[i]=r-l+1;
	if (l==r) return;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
void down(int i)
{
	int j;
	if (tag[i]>0)
	{
		j=i*2;
		mx[j]-=tag[i];t[j]-=1LL*cnt[j]*tag[i];tag[j]+=tag[i];
		j++;
		mx[j]-=tag[i];t[j]-=1LL*cnt[j]*tag[i];tag[j]+=tag[i];
		tag[i]=0;
	}
}
void update(int i)
{
	int j=i*2,k=i*2+1;
	cnt[i]=cnt[j]+cnt[k];
	mx[i]=min(mx[j],mx[k]);
	t[i]=t[j]+t[k];
}
void clr(int i,int l,int r)
{
	if (l==r)
	{
		tag[i]=0;mx[i]=1LL<<60;
		t[i]=0;cnt[i]=0;
		return;
	}
	int mid=(l+r)>>1;
	down(i);
	if (mx[i*2]<=0) clr(i*2,l,mid);
	if (mx[i*2+1]<=0) clr(i*2+1,mid+1,r);
	update(i);
}
void change(int i,int l,int r,int ll,int rr,int k)
{
	int mid=(l+r)>>1;
	if (ll<=l&&r<=rr)
	{
		mx[i]-=k;
		t[i]-=1LL*cnt[i]*k;
		tag[i]+=k;
		if (mx[i]<=0)
		{
			clr(i,l,r);
			update(i);
		}
		return;
	}
	down(i);
	if (ll<=mid) change(i*2,l,mid,ll,rr,k);
	if (rr>mid) change(i*2+1,mid+1,r,ll,rr,k);
	update(i);
}
LL query(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return t[i];
	LL res=0;
	int mid=(l+r)>>1;
	down(i);
	if (ll<=mid) res+=query(i*2,l,mid,ll,rr);
	if (rr> mid) res+=query(i*2+1,mid+1,r,ll,rr);
	return res;
}
int main()
{
	// 3*16+1*6+10=48+16
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d%d",&l[i],&r[i],&c[i],&p[i]);
//	n=1000000,m=200000,k=1000000;
//	for (int i=1;i<=m;i++) l[i]=1,r[i]=n,c[i]=n/i,p[i]=n/i;
	build(1,1,n);
	for (int i=1;i<=m;i++) id[i]=i;
	sort(id+1,id+1+m,cmp);
	long long ans=0;
	for (int j=1;j<=m;j++)
	{
		int i=id[j];
		LL s1=query(1,1,n,l[i],r[i]);
		change(1,1,n,l[i],r[i],c[i]);
		s1-=query(1,1,n,l[i],r[i]);
		ans+=s1*p[i];
	}
	cout<<ans<<endl;
}