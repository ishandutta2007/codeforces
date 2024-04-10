#include<cstdio> 
#include<algorithm>
using namespace std;
struct wp
{
	int val;
	int cost;
}a[200005],b[200005];
bool cmp1(wp x,wp y)
{
	return x.val<y.val;
}
struct mst
{
	int atk,def;
	int cost;
}f[200005];
bool cmp2(mst x,mst y)
{
	return x.atk<y.atk;
}
int n,m,p,maxn[800005],tag[800005];
void Add(int k,int val)
{
	maxn[k]+=val;
	tag[k]+=val;
}
void pushdown(int k)
{
	Add(k*2,tag[k]);
	Add(k*2+1,tag[k]);
	tag[k]=0;
}
void build(int k,int l,int r)
{
	if(l==r) 
	{
		maxn[k]=-b[l].cost;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	maxn[k]=max(maxn[2*k],maxn[2*k+1]);
}
void modify(int k,int l,int r,int ql,int qr,int val)
{
	if(ql>r || qr<l) return;
	if(ql<=l && qr>=r) return Add(k,val);
	int mid=(l+r)/2;
	pushdown(k); 
	modify(k*2,l,mid,ql,qr,val);
	modify(k*2+1,mid+1,r,ql,qr,val);
	maxn[k]=max(maxn[2*k],maxn[2*k+1]);
}
int query(int k,int l,int r,int ql,int qr)
{
	if(ql>r || qr<l) return -2e9;
	if(ql<=l && qr>=r) return maxn[k];
	int mid=(l+r)/2;
	pushdown(k);
	return max(query(k*2,l,mid,ql,qr),query(k*2+1,mid+1,r,ql,qr));
}
void print(int k,int l,int r,int val=0)
{
	for(int i=1;i<=val;i++) printf("---");
	printf("tag=%d maxn=%d\n",tag[k],maxn[k]);
	if(l==r) return;
	int mid=(l+r)/2;
	print(2*k,l,mid,val+1);
	print(2*k+1,mid+1,r,val+1);
}
int find(int x)
{
	int l=1,r=m+1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(b[mid].val<=x) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].val,&a[i].cost);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].val,&b[i].cost);
	}
	b[m+1].val=2e9;
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&f[i].atk,&f[i].def,&f[i].cost);
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1,cmp1);
	sort(f+1,f+p+1,cmp2);
	build(1,1,m);
//	print(1,1,m,0);
	int now=1,ans=-2e9;
	for(int i=1;i<=n;i++)
	{
		while(now<=p && f[now].atk<a[i].val)
		{
			int id=find(f[now].def);
			if(id<=m) modify(1,1,m,id,m,f[now].cost);
			now++;
		}
		ans=max(ans,query(1,1,m,1,m)-a[i].cost);
	}
	printf("%d\n",ans);
	return 0;
}