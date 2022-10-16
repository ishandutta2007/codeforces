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
int n,m;
struct node
{
	int a,b,v;
	bool operator<(const node&w)const
	{
		return v==w.v?a==w.a?b<w.b:a<w.a:v<w.v;
	}
};
multiset<node>s,v[105];
int as[105][105];
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		m=read();
		s.clear();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int a=read();
				s.insert((node){i,j,a});
				v[i].insert((node){i,j,a});
			}
		}
		for(int i=1;i<=m;i++)
		{
			node a=(*s.begin());
			s.erase(s.begin());
			int o=a.a;
//			cout<<a.a<<" "<<a.b<<" sss "<<a.v<<"\n";
			for(int j=1;j<o;j++)
			{
				as[j][i]=(*--v[j].end()).v;
//				cout<<<<" ";
				s.erase(s.find(*--v[j].end()));
				v[j].erase(--v[j].end());
			}
			as[o][i]=a.v;
//			cout<<a.v<<" ";
			v[o].erase(v[o].find(a));
			for(int j=o+1;j<=n;j++)
			{
//			cout<<i<<" "<<j<<"\n";
				as[j][i]=(*--v[j].end()).v;
//				cout<<(*--v[j].end()).v<<" ";
				s.erase(s.find(*--v[j].end()));
				v[j].erase(--v[j].end());
			}
//			puts("");
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)cout<<as[i][j]<<" ";
			puts("");
		}
	}
	return 0;
}