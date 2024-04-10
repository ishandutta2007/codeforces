#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 605
#define maxm 360005
#define inf 0x3f3f3f3f

int n,m,q,d[maxn][maxn];
int uu[maxm],vv[maxm],l[maxm];
int xx[maxm],yy[maxm],w[maxm];
vector<pii>e[maxn];
int now[maxn];
set< pii > orz;
signed main()
{
	memset(d,63,sizeof d);
	n=read(),m=read();
	For(i,1,m)
		xx[i]=read(),yy[i]=read(),d[xx[i]][yy[i]]=d[yy[i]][xx[i]]=w[i]=read(),
		e[xx[i]].pb(mkp(yy[i],w[i])),e[yy[i]].pb(mkp(xx[i],w[i]));
	For(i,1,n)d[i][i]=0;
	For(k,1,n)For(i,1,n)For(j,1,n)d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
	q=read();
	For(i,1,q)uu[i]=read(),vv[i]=read(),l[i]=read();
	For(x,1,n)
	{
	//	cout<<"work x "<<x<<endl;
		memset(now,63,sizeof now);
		For(i,1,q){
			int u=uu[i],v=vv[i],L=l[i];
			now[v]=min(now[v],d[x][u]-L);
			now[u]=min(now[u],d[x][v]-L);
		}
		for(auto t:e[x]){
			bool ok=0;
			int y=t.fi,w=t.se;
			For(v,1,n){
				if(now[v]>=inf)continue;
			//	cout<<v<<' '<<now[v]<<' '<<now[v]+d[y][v]+w<<endl;
				if(now[v]+d[y][v]+w <= 0) {
					ok=1;
					break;
				}
			}
			if(ok)//cout<<"OK "<<x<<" "<<y<<endl, 
				orz.insert(mkp(min(x,y),max(x,y)));
		}
	}
	cout<<orz.size();
	return 0;
}