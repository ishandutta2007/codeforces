#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int a[11][xx],tt[xx],n;
struct node
{
	int id[11],val;
	bool operator<(const node&w)const
	{
		if(val!=w.val)
		return val>w.val;
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(id[i]<w.id[i])return 1;
				if(id[i]>w.id[i])return 0;
			}
			return 0;
		}
	}
};
struct nod
{
	int id[11];
	bool operator<(const nod&w)const
	{
		for(int i=1;i<=n;i++)
		{
			if(id[i]<w.id[i])return 1;
			if(id[i]>w.id[i])return 0;
		}
		return 0;
	}
};
set<node>s;
map<nod,int>mp;
signed main(){
	n=read();
	int sm=0;
	for(int i=1;i<=n;i++)
	{
		tt[i]=read();
		for(int j=1;j<=tt[i];j++)a[i][j]=read();
		sm+=a[i][tt[i]];
	}
	node o;
	o.val=sm;
	for(int i=1;i<=n;i++)o.id[i]=tt[i];
	s.insert(o);
	int q=read();
	while(q--)
	{
		nod t;
		for(int i=1;i<=n;i++)t.id[i]=read();
		mp[t]=1;
	}
	while(1)
	{
		o=*s.begin();
		s.erase(s.begin());
		nod p;
		memcpy(p.id,o.id,sizeof(o.id));
		if(!mp[p])
		{
			for(int i=1;i<=n;i++)cout<<p.id[i]<<" ";
			puts("");
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(p.id[i]!=1)
			{
				node w=o;
				w.val-=a[i][p.id[i]];
				w.val+=a[i][p.id[i]-1];
				w.id[i]--;
				s.insert(w);
			}
		}
	}
    return 0;
}