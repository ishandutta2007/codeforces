#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL inf=1e+18;
const int N=30010;
int ida[N],idb[N],id[N],c[N],a[N],b[N],p[N];
struct rec
{
	LL f[3][3];
	void init(int p)
	{
		for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			f[i][j]=-inf;
		f[0][1]=f[1][0]=0;
		if (c[p]!=p) f[0][0]=1LL*a[p]*b[p];
	}
};
rec t[N*4];
int n,q;

int cmpa(int i,int j) { return a[i]<a[j];}
int cmpb(int i,int j) { return b[i]<b[j];}
int upmax(LL &a,LL b) { if (a<b) a=b;}

LL calc(int l,int r)
{
	int len=r-l+1;
	LL ans=-inf;
	for (int i=1;i<=len;i++) p[i]=i;
	while (1)
	{
		int flag=1;
		for (int i=l;i<=r;i++)
		if (c[i]==p[i-l+1]+l-1) flag=0;
		if (flag)
		{
			LL res=0;
			for (int i=l;i<=r;i++) res+=1LL*a[i]*b[p[i-l+1]+l-1];
			ans=max(ans,res);
		}
		
		if (!next_permutation(p+1,p+1+len)) break;
	}
//	printf("%d %d %lld\n",l,r,ans);
	return ans;
}
void update(int i,int L,int R)
{
	for (int l=0;l<3;l++)
	for (int r=0;r<3;r++)
		t[i].f[l][r]=-inf;
	int mid=(L+R)>>1;
	int len1=mid-L+1,len2=R-mid;
	int l=i*2,r=i*2+1;
	for (int ll=0;ll<3;ll++)
	for (int lr=0;lr<3;lr++)
	if (ll+lr<=len1)
	for (int rl=0;rl<3;rl++)
	if (lr+rl<=3)
	for (int rr=0;rr<3;rr++)
	if (rl+rr<=len2)
	{
		upmax(t[i].f[ll][rr],t[l].f[ll][lr]+t[r].f[rl][rr]+calc(mid+1-lr,mid+rl));
		if (ll+lr==len1&&ll+lr+rl<=2)
		upmax(t[i].f[ll+lr+rl][rr],t[l].f[ll][lr]+t[r].f[rl][rr]);
		if (rl+rr==len2&&lr+rl+rr<=2)
		upmax(t[i].f[ll][lr+rl+rr],t[l].f[ll][lr]+t[r].f[rl][rr]);
	}
}
void build(int i,int l,int r)
{
	if (l==r)
	{
		t[i].init(l);
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);build(i*2+1,mid+1,r);
	update(i,l,r);
}
void change(int i,int l,int r,int k)
{
	if (l==r)
	{
		t[i].init(k);
		return;
	}
	int mid=(l+r)>>1;
	if (k<=mid) change(i*2,l,mid,k);
	else change(i*2+1,mid+1,r,k);
	update(i,l,r);
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) ida[i]=idb[i]=i;
	sort(ida+1,ida+n+1,cmpa);
	sort(idb+1,idb+n+1,cmpb);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	
	for (int i=1;i<=n;i++) id[idb[i]]=i;
	for (int i=1;i<=n;i++) c[i]=id[ida[i]];
	for (int i=1;i<=n;i++) id[ida[i]]=i;
	build(1,1,n);
	
	
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=id[x],y=id[y];
		swap(c[x],c[y]);
		
		change(1,1,n,x);
		change(1,1,n,y);
		printf("%I64d\n",t[1].f[0][0]);
		
	}
	return 0;
}