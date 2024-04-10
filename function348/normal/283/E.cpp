#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N=100010;
int n,m,num;
int a[N];
PIII c[N*2];
int rev[N*4],t[N*4];
void change(int i,int l,int r,int ll,int rr)
{
	if (ll>rr) return;
	if (ll<=l&&r<=rr)
	{
		t[i]=r-l+1-t[i];
		rev[i]^=1;
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) change(i*2,l,mid,ll,rr);
	if (rr> mid) change(i*2+1,mid+1,r,ll,rr);
	t[i]=t[i*2]+t[i*2+1];
	if (rev[i]) t[i]=r-l+1-t[i];
}
int query(int i,int l,int r,int ll,int rr)
{
	if (ll>rr) return 0;
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)>>1,res=0;
	if (ll<=mid) res+=query(i*2,l,mid,ll,min(mid,rr));
	if (rr> mid) res+=query(i*2+1,mid+1,r,max(ll,mid+1),rr);
	if (rev[i]) res=rr-ll+1-res;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=lower_bound(a+1,a+1+n,x)-a;
		y=upper_bound(a+1,a+1+n,y)-a-1;
		if (x==y) continue;
		c[++num]=MP(x  ,MP(x,y));
		c[++num]=MP(y+1,MP(x,y));
	}
	sort(c+1,c+1+num);
	LL ans=1LL*n*(n-1)*(n-2)/6;
	for (int i=1,j=1;i<=n;i++)
	{
		while (c[j].FR==i&&j<=num)
		{
			change(1,1,n,c[j].SC.FR,c[j].SC.SC);
			j++;
		}
		int c=query(1,1,n,1,i-1)+query(1,1,n,i+1,n);
		ans-=1LL*c*(c-1)/2;
		change(1,1,n,i,i);
	}
	cout<<ans<<endl;
	return 0;
}