#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int a[xx],id[xx],lsh[xx],sum[xx],n,m;
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=n*m;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
int bel(int x){return (x-1)/m+1;}
struct nod
{
	int x;
	bool operator<(const nod&w)const{return bel(x)==bel(w.x)?x>w.x:bel(x)<bel(w.x);}
};
map<int,set<nod> >mp;
int s[305][305];
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		m=read();
		mp.clear();
		for(int i=1;i<=n*m;i++)a[i]=lsh[i]=read();
		sort(lsh+1,lsh+n*m+1);
		for(int i=1;i<=n*m;i++)mp[lsh[i]].insert((nod){i});
		for(int i=1;i<=n*m;i++)
		{
			id[i]=mp[a[i]].begin()->x;
			mp[a[i]].erase(mp[a[i]].begin());
		}
		for(int i=1;i<=n*m;i++)s[bel(id[i])][id[i]-(bel(id[i])-1)*m]=i;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
//				cout<<s[i][j]<<" ";
				ans+=ask(s[i][j]);
				add(s[i][j],1);
			}
//			puts("");
			for(int j=1;j<=m;j++)add(s[i][j],-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}