#include<bits/stdc++.h>
using namespace std;
const int N=300005,bs=1000000000,mx=bs*2,inf=2e9;
const long long inf2=9e18;
struct ln
{
	int k,b;
	long long val(int x){return 1ll*k*x+b;}
}tr[N<<4],a[N];
int n,lc[N<<2],rc[N<<2],rt,t,op[N],bg[N],ed[N],q[N];
long long ans[N];
vector<pair<int,ln>>s;
vector<ln>ls[N<<2];
void ins(int &k,int l,int r,ln v)
{
	if(!k||tr[k].k==-inf)
	{
		if(!k)
		{
			k=++t;
			tr[k]={-inf,-inf};
		}
		s.emplace_back(k,tr[k]);
		tr[k]=v;
		return;
	}
	int mid=1ll*l+r>>1;
	if(tr[k].val(mid-bs)<v.val(mid-bs))
	{
		s.emplace_back(k,tr[k]);
		swap(tr[k],v);
	}
	if(l==r) return;
	if(v.val(l-bs)>tr[k].val(l-bs)) ins(lc[k],l,mid,v);
	else ins(rc[k],mid+1,r,v);
}
long long ask(int k,int l,int r,int x)
{
	if(!k||tr[k].k==-inf) return -inf2;
	long long v=tr[k].val(x);
	if(l==r) return v;
	int mid=1ll*l+r>>1;
	if(x<=mid-bs) v=max(v,ask(lc[k],l,mid,x));
	else v=max(v,ask(rc[k],mid+1,r,x));
	return v;
}
void addl(int k,int l,int r,int a,int b,ln v)
{
	if(l==a&&r==b)
	{
		ls[k].push_back(v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) addl(k<<1,l,mid,a,b,v);
	else if(a>mid) addl(k<<1|1,mid+1,r,a,b,v);
	else addl(k<<1,l,mid,a,mid,v),addl(k<<1|1,mid+1,r,mid+1,b,v);
}
void sol(int k,int l,int r)
{
	int d=s.size();
	for(auto i:ls[k])
		ins(rt,0,mx,i);
	if(l==r)
	{
		if(op[l]==3)
		{
			if(!rt||tr[rt].k==inf)
				ans[l]=-inf2;
			else
				ans[l]=ask(rt,0,mx,q[l]);
		}
	}
	else
	{
		int mid=l+r>>1;
		sol(k<<1,l,mid);
		sol(k<<1|1,mid+1,r);
	}
	while(s.size()>d)
	{
		tr[s.back().first]=s.back().second;
		s.pop_back();
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%d%d",&a[i].k,&a[i].b);
			bg[i]=i;
		}
		if(op[i]==2)
		{
			int d;
			scanf("%d",&d);
			ed[d]=i;
		}
		if(op[i]==3)
			scanf("%d",&q[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(op[i]==1)
		{
			if(!ed[i])
				ed[i]=n;
			addl(1,1,n,bg[i],ed[i],a[i]);
		}
	}
	sol(1,1,n);
	for(int i=1;i<=n;i++)
	{
		if(op[i]==3)
		{
			if(ans[i]==-inf2)
				puts("EMPTY SET");
			else
				printf("%lld\n",ans[i]);
		}
	}
	return 0;
}