#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define inf 1000000000

struct node
{
	int l,r,id;
	node() {}
	node(int l1,int r1,int id1):l(l1),r(r1),id(id1) {}
	inline bool operator <(const node &y) const { return l<y.l; }
};

set<node> st;
vector<pii> v[300010];

int c[300010],n,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline set<node>::iterator split(int x)
{
	set<node>::iterator it=st.upper_bound(node(x,0,0));it--;
	node hh=*it;
	if (hh.l==x) return it;
	st.erase(hh);
	st.insert(node(hh.l,x-1,hh.id));
	st.insert(node(x,hh.r,hh.id));
	return st.lower_bound(node(x,hh.r,hh.id));
}

inline ll querycnt(int mid)
{
	memset(c,0,sizeof(c));
	ll ans=0,res=0;
	int now=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			pii hh=v[i][j];
			c[hh.first]+=hh.second;
			if (hh.first<=now) res+=hh.second;
		}
		while (res>=mid)
		{
			for (int j=0;j<v[now].size();j++) res-=v[now][j].second;
			now++;res+=c[now];
		}
		ans+=now-1;
	}
	return ans;
}

inline ll querysum(int mid)
{
	memset(c,0,sizeof(c));
	ll ans=0,res1=0,res2=0;
	int now=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			pii hh=v[i][j];
			c[hh.first]+=hh.second;
			if (hh.first<=now) res1+=hh.second,res2+=(ll)hh.first*hh.second;
		}
		while (res1>=mid)
		{
			for (int j=0;j<v[now].size();j++)
			{
				pii hh=v[now][j];
				res1-=hh.second;res2-=(ll)hh.first*hh.second;
				ans+=(ll)hh.second*(now-hh.first+1)*(n-i+1);
			}
			now++;res1+=c[now];res2+=(ll)c[now]*now;
		}
		ans+=res1*now-res2;
	}
	return ans;
}

int main()
{
	n=rd();k=rd();
	st.insert(node(1,inf,0));
	for (int i=1;i<=n;i++)
	{
		int x=rd(),y=rd()-1;
		set<node>::iterator l=split(x),r=split(y+1);
		for (set<node>::iterator it=l;it!=r;it++) v[i].push_back(pii((*it).id+1,(*it).r-(*it).l+1));
		st.erase(l,r);
		st.insert(node(x,y,i));
	}
	int l=1,r=inf;
	while (l<r)
	{
		int mid=((l+r)>>1)+1;
		if (querycnt(mid)>=k) l=mid;
		else r=mid-1;
	}
	printf("%lld\n",querysum(l)-(ll)(querycnt(l)-k)*l);
	return 0;
}