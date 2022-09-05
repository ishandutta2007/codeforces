//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,m;
typedef unsigned long long ull;
struct state
{
	int a[4][4];
	ull geths()
	{
		ull hs=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				hs=hs*123123+a[i][j];
			}
		}
		return hs;
	}
	void rotate(int ax,int ay,int bx,int by)
	{
		int t=a[ax][ay];
		for(int i=ax;i<bx;i++)a[i][ay]=a[i+1][ay];
		for(int i=ay;i<by;i++)a[bx][i]=a[bx][i+1];
		for(int i=bx;i>ax;i--)a[i][by]=a[i-1][by];
		for(int i=by;i>ay;i--)a[ax][i]=a[ax][i-1];
		a[ax][ay+1]=t;
	}
};
const int maxst=2333;
state st[maxst];
int tot;
unordered_map<ull,int> hsmp;
int getid(state x)
{
	int &id=hsmp[x.geths()];
	if(id==0)
	{
		id=++tot;
		assert(tot<maxst);
		st[tot]=x;
	}
	return id;
}
int dis[maxst],q[maxst],pre[maxst];
pair<pair<int,int>,pair<int,int> > prer[maxst];
void bfs(state S)
{
	memset(dis,-1,sizeof(dis));
	dis[getid(S)]=0;
	int qn=0;
	q[qn++]=getid(S);
	for(int i=0;i<qn;i++)
	{
		int x=q[i];
		for(int ax=0;ax+1<n;ax++)
		{
			for(int ay=0;ay+1<m;ay++)
			{
				int bx=ax+1;
				for(int by=ay+1;by<m&&by<=ay+2;by++)
				{
					state nxt=st[x];
					nxt.rotate(ax,ay,bx,by);
					int nxtid=getid(nxt);
					if(dis[nxtid]==-1)
					{
						dis[nxtid]=dis[x]+1;
						pre[nxtid]=x;
						prer[nxtid]=MP(MP(ax,ay),MP(bx,by));
						q[qn++]=nxtid;
					}
				}
			}
		}
	}
	cerr<<"qn="<<qn<<" "<<dis[qn-1]<<endl;
}
vector<vector<int> > cmd;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int id[22][22];
bool ban[22][22];
pair<int,int> idp[422];
int a[22][22],M;
pair<int,int> pos[422];
int& getv(int id){return a[idp[id].FF][idp[id].SS];}
void add(vector<int> v)
{
	vector<int> nv;
	for(int i=0;i<v.size();i++)nv.PB(getv(v[i]));
	cmd.PB(nv);
	int tmp=getv(v.back());
	for(int i=int(v.size())-1;i>0;i--)getv(v[i])=getv(v[i-1]);
	getv(v[0])=tmp;
	for(int i=0;i<v.size();i++)pos[getv(v[i])]=idp[v[i]];
}
bool valid(int x,int y){return x>=0&&x<n&&y>=0&&y<m&&!ban[x][y];}
void go(pair<int,int> p,int dir)
{
	int x=p.FF,y=p.SS;
	int bx=x+dx[dir],by=y+dy[dir];
	assert(valid(x,y)&&valid(bx,by));
	int nd,cx,cy,tx,ty;
	nd=dir^2;
	cx=bx+dx[nd],cy=by+dy[nd];
	tx=cx-dx[dir],ty=cy-dy[dir];
	if(valid(cx,cy)&&valid(tx,ty))
	{
		add({id[x][y],id[bx][by],id[cx][cy],id[tx][ty]});
		return;
	}
	nd=dir^3;
	cx=bx+dx[nd],cy=by+dy[nd];
	tx=cx-dx[dir],ty=cy-dy[dir];
	if(valid(cx,cy)&&valid(tx,ty));
	{
		add({id[x][y],id[bx][by],id[cx][cy],id[tx][ty]});
		return;
	}
	assert(false);
}
void go(pair<int,int> p,pair<int,int> q)
{
	while(p!=q)
	{
		while(p.FF<q.FF&&valid(p.FF+dx[0],p.SS+dy[0]))go(p,0),p.FF++;
		while(p.FF>q.FF&&valid(p.FF+dx[1],p.SS+dy[1]))go(p,1),p.FF--;
		while(p.SS<q.SS&&valid(p.FF+dx[2],p.SS+dy[2]))go(p,2),p.SS++;
		while(p.SS>q.SS&&valid(p.FF+dx[3],p.SS+dy[3]))go(p,3),p.SS--;
	}
}
void decm()
{
	for(int i=0;i+1<n;i++)
	{
		pair<int,int> p=pos[id[i][m-1]];
		if(i+2==n)
		{
			go(pos[id[n-2][m-1]],MP(0,0));
			p=pos[id[n-1][m-1]];
		}
		go(p,MP(i,m-2));
		go(MP(i,m-2),MP(i,m-1));
		ban[i][m-1]=1;
	}
	go(pos[id[n-2][m-1]],MP(n-2,m-2));
	add({id[n-2][m-2],id[n-2][m-1],id[n-1][m-1],id[n-1][m-2]});
	m--;
}
void decn()
{
	for(int i=0;i+1<m;i++)
	{
		pair<int,int> p=pos[id[n-1][i]];
		if(i+2==m)
		{	
			go(pos[id[n-1][m-2]],MP(0,0));
			p=pos[id[n-1][m-1]];
		}
		go(p,MP(n-2,i));
		go(MP(n-2,i),MP(n-1,i));
		ban[n-1][i]=1;
	}
	go(pos[id[n-1][m-2]],MP(n-2,m-2));
	add({id[n-2][m-2],id[n-1][m-2],id[n-1][m-1],id[n-2][m-1]});
	n--;
}
void addcycle(int ax,int ay,int bx,int by)
{
	vector<int> v;
	for(int i=ay;i<by;i++)v.PB(id[ax][i]);
	for(int i=ax;i<bx;i++)v.PB(id[i][by]);
	for(int i=by;i>ay;i--)v.PB(id[bx][i]);
	for(int i=bx;i>ax;i--)v.PB(id[i][ay]);
	add(v);
}
void solve()
{
	assert(n==2&&m==3);
	state S;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]<=3)S.a[i][j]=a[i][j];
			else S.a[i][j]=a[i][j]-M+3;
		}
	}
	bfs(S);
	state T;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)T.a[i][j]=i*3+j+1;
	int p=getid(T);
	vector<pair<pair<int,int>,pair<int,int> > > v;
	while(pre[p])
	{
		v.PB(prer[p]);
		p=pre[p];
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		addcycle(v[i].FF.FF,v[i].FF.SS,v[i].SS.FF,v[i].SS.SS);
	}
}
int main()
{
	cin>>n>>m;
	M=m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			id[i][j]=i*m+j+1;
			idp[id[i][j]]=MP(i,j);
			cin>>a[i][j];
			pos[a[i][j]]=MP(i,j);
		}
	}
	while(m>3)decm();
	while(n>2)decn();
	solve();
	int sum=0;
	for(int i=0;i<cmd.size();i++)
	{
		sum+=cmd[i].size();
	}
	assert(sum<=100000);
	putsi(cmd.size());
	for(int i=0;i<cmd.size();i++)
	{
		puti(cmd[i].size());
		for(int j=0;j<cmd[i].size();j++)
		{
			puti(cmd[i][j]);
		}
		puts("");
	}
	cerr<<"sum="<<sum<<endl;
	return 0;
}