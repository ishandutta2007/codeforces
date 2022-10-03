#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define inf 1000000000000000000LL

pll h[1010];

ll L;
int a[1010],a1[1010],a2[1010],n;
bool vis[1010];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll ask(int x,ll y)
{
	printf("? %d %lld\n",x,y);
	fflush(stdout);
	return rd();
}

inline ll calc(int x,ll y,ll ql,ll qr)
{
	ll l=ql,r=qr;
	while (l<r)
	{
		ll mid=((l+r)>>1)+1;
		if (ask(x,mid)<=y) l=mid;
		else r=mid-1;
	}
	return l;
}

ll hhh;

inline vector<int> select(vector<int> v,ll hh,int k,ll ql,ll qr)
{
	ll mid=calc(v[rand()%v.size()],hh,ql,qr);
	hhh=mid;
	vector<int> v1,v2,v3;
	for (int t:v)
	{
		ll p=ask(t,mid);
		if (p<hh) v3.push_back(t);
		else if (p>hh) v1.push_back(t);
		else
		{
			ll q=ask(t,mid+1);
			if (q==hh) v3.push_back(t);
			else v2.push_back(t);
		}
	}
	if (v1.size()>=k) return select(v1,hh,k,ql,mid);
	else if (v1.size()+v2.size()<k)
	{
		vector<int> res;
		for (int t:v1) res.push_back(t);
		for (int t:v2) res.push_back(t);
		vector<int> res1=select(v3,hh,k-v1.size()-v2.size(),mid,qr);
		for (int t:res1) res.push_back(t);
		return res;
	}
	else
	{
		vector<int> res;
		for (int t:v1) res.push_back(t);
		for (int i=0;i<k-v1.size();i++) res.push_back(v2[i]);
		return res;
	}
}

inline void solve(int l,int r,ll ql,ll qr)
{
	if (l==r)
	{
		h[a[l]].first=ql;h[a[l]].second=qr;
		return;
	}
	vector<int> v;
	for (int i=l;i<=r;i++) v.push_back(a[i]);
	int mid=(l+r)>>1;
	ll hh=L/n*mid;
	vector<int> g=select(v,hh,mid-l+1,ql,qr);
	for (int i=l;i<=r;i++) vis[a[i]]=false;
	for (int t:g) vis[t]=true;
	int t1=0,t2=0;
	for (int i=l;i<=r;i++) if (vis[a[i]]) a1[++t1]=a[i];else a2[++t2]=a[i];
	for (int i=1;i<=t1;i++) a[l+i-1]=a1[i];
	for (int i=1;i<=t2;i++) a[l+t1+i-1]=a2[i];
	ll now=hhh;
	solve(l,mid,ql,now);solve(mid+1,r,now,qr);
}

int main()
{
	srand(19260816);
	n=rd();L=rd();
	for (int i=1;i<=n;i++) a[i]=i;
	solve(1,n,0,inf);
	puts("!");
	for (int i=1;i<=n;i++) printf("%lld %lld\n",h[i].first,h[i].second);
	fflush(stdout);
	return 0;
}