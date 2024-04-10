#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
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

#define mod 998244353
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};

#define maxn 400005
#define inf 0x3f3f3f3f

int n,m,k;
int wy[555][555],wx[555][555];

int dis[555][555][12];
bool vis[555][555][12];
struct node{
	int x,y,z;
};
node orz[maxn];
int len;
int bfs(int sx,int sy)
{
//	memset(dis,63,sizeof dis);
//	queue<pii>q;
//	q.push(mkp(x,y));
	dis[sx][sy][0]=0;//len=0;
//	st.push((node){sx,sy,0});
	For(i,1,k/2){
	//	queue<pii>q2;
		For(s,-(i-1),i-1)
		for(int gap=(i-1)-abs(s),t=-gap;t<=gap;t+=2)
		{
			int x=sx+s,y=sy+t;
			if(x>=1&&y>=1&&x<=n&&y<=m);
			else continue;
			if(dis[x][y][i-1]>=inf)continue; 
			//st.push((node){x,y,i-1});
			int xx,yy,dd;
			xx=x+1,yy=y,dd=wx[x][y]+dis[x][y][i-1];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&dd<dis[xx][yy][i])
				dis[xx][yy][i]=dd;
			xx=x,yy=y+1,dd=wy[x][y]+dis[x][y][i-1];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&dd<dis[xx][yy][i])
				dis[xx][yy][i]=dd;
			xx=x-1,yy=y,dd=wx[x-1][y]+dis[x][y][i-1];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&dd<dis[xx][yy][i])
				dis[xx][yy][i]=dd;
			xx=x,yy=y-1,dd=wy[x][y-1]+dis[x][y][i-1];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&dd<dis[xx][yy][i])
				dis[xx][yy][i]=dd;
			dis[x][y][i-1]=inf;
		}
	//	For(s,1,n)For(t,1,n)cout<<dis[s][t][i]<<" \n"[t==n];
	}
	int res=inf;
	For(s,-k/2,k/2)
		for(int gap=(k/2)-abs(s),t=-gap;t<=gap;t+=2)
		{
			int x=sx+s,y=sy+t;
			if(x>=1&&y>=1&&x<=n&&y<=m);
			else continue;
			if(dis[x][y][k/2]>=inf)continue;
			res=min(res,dis[x][y][k/2]); 
			dis[x][y][k/2]=inf;
		}
	return res;
}

signed main()
{
//	freopen("data","r",stdin);
//	freopen("orz","w",stdout);
	memset(dis,63,sizeof dis);
	memset(wx,63,sizeof wx);
	memset(wy,63,sizeof wy);
	n=read(),m=read(),k=read();
	For(i,1,n)For(j,1,m-1)wy[i][j]=read();
	// (i,j)->(i,j+1) right 
	For(i,1,n-1)For(j,1,m)wx[i][j]=read();
	// down
	if(k&1){
		For(i,1,n)For(j,1,m)cout<<-1<<" \n"[j==m];
		return 0;
	}
	For(i,1,n){
		For(j,1,m){
			cout<<bfs(i,j)*2<<" \n"[j==m];
		}//cout<<"i: "<<i<<endl;
	}
	
	return 0;
}