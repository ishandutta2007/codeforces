#include<bits/stdc++.h>
using namespace std;
const int N=3000005;
int a[N],b[N],c[N],s[N],n,m,q;
vector<int>v;
struct node
{
	int sum,tag,val;	
}tr[N];
void pushdown(int k)
{
	if(tr[k].tag==0)
	{
		tr[k].tag=-1;
		tr[k<<1].tag=tr[k<<1|1].tag=0;
		tr[k<<1].val=0;
		tr[k<<1|1].val=0;	
	}
	if(tr[k].tag==1)
	{
		tr[k].tag=-1;
		tr[k<<1].tag=tr[k<<1|1].tag=1;
		tr[k<<1].val=tr[k<<1].sum;
		tr[k<<1|1].val=tr[k<<1|1].sum;	
	}
}
void build(int k,int l,int r)
{
	tr[k].tag=-1;
	if(l==r)
	{
		tr[k].sum=tr[k].val=s[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
	tr[k].val=tr[k<<1].val+tr[k<<1|1].val; 
}
void update(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k].val=tr[k].sum*v;
		tr[k].tag=v;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b,v);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
	else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k].val=tr[k<<1].val+tr[k<<1|1].val; 
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		v.push_back(a[i]);
		v.push_back(b[i]+1);
		c[i]--;
	}
	v.push_back(1);
	v.push_back(n+1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	m=v.size();
	for(int i=0;i<v.size()-1;i++)
		s[i+1]=v[i+1]-v[i];
	for(int i=1;i<=q;i++)
	{
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		b[i]=lower_bound(v.begin(),v.end(),b[i]+1)-v.begin();
	}
	build(1,1,m);
	for(int i=1;i<=q;i++)
	{
		update(1,1,m,a[i],b[i],c[i]);
		printf("%d\n",tr[1].val);
	}
	return 0;
}