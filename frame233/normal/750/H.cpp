// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
char s[N][N];
int n,m,q,A,B;
int fa[N*N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) fa[x]=y;
}
inline int getid(int x,int y)
{
	return x*(m+1)+y+1;
}
int X[15],Y[15];
ll S[N*N*28];
int t[105],val[N][N];
int FA[N*N];
int FIND(int x){return x==FA[x]?x:FA[x]=FIND(FA[x]);}
inline void MERGE(int x,int y)
{
	x=FIND(x),y=FIND(y);
	if(x!=y) FA[x]=y;
}
int main()
{
	read(n,m,q);
	for(int i=1;i<=n;++i) read_str(s[i]+1);
	for(int i=2;i<=n+1;++i) s[i][0]='#';
	for(int i=0;i<n;++i) s[i][m+1]='#';
	for(int i=2;i<=m+1;++i) s[0][i]='#';
	for(int i=0;i<m;++i) s[n+1][i]='#';
	++n,++m;
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) if(!s[i][j]) s[i][j]='.';
	for(int i=1;i<=(n+1)*(m+1);++i) fa[i]=i;
	A=getid(n,0),B=getid(0,m);
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			if(s[i][j]=='.') continue;
			for(int dir=0;dir<8;++dir)
			{
				int u=i+dx[dir],v=j+dy[dir];
				if(u>=0&&v>=0&&u<=n&&v<=m&&s[u][v]=='#') merge(getid(i,j),getid(u,v));
			}
		}
	}
	if(find(A)==find(B))
	{
		while(q--){puts("NO");fflush(stdout);}
		return 0;
	}
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) val[i][j]=find(getid(i,j));
	int p=0;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			if(s[i][j]=='.'&&i>=1&&j>=1&&i<n&&j<m&&(i!=1||j!=1)&&(i+1!=n||j+1!=m))
			{
				std::vector<int> V;
				for(int dir=0;dir<8;++dir)
				{
					int u=i+dx[dir],v=j+dy[dir];
					if(u>=0&&v>=0&&u<=n&&v<=m) V.pb(val[u][v]);
				}
				std::sort(V.begin(),V.end()),V.erase(std::unique(V.begin(),V.end()),V.end());
				for(int i=0;i<SZ(V);++i) for(int j=i+1;j<SZ(V);++j) S[++p]=((ll)V[i]<<32)|V[j];
			}
		}
	}
	std::sort(S+1,S+p+1);
	p=std::unique(S+1,S+p+1)-S-1;
	A=find(A),B=find(B);
	while(q--)
	{
		int k;read(k);
		int pos=0;
		for(int _=1;_<=k;++_)
		{
			int i,j;read(i,j);s[i][j]='#';
			X[_]=i,Y[_]=j;
			t[++pos]=val[i][j];
			for(int dir=0;dir<8;++dir)
			{
				int u=i+dx[dir],v=j+dy[dir];
				if(u>=0&&v>=0&&u<=n&&v<=m&&s[u][v]=='#') t[++pos]=val[u][v];
			}
		}
		t[++pos]=A,t[++pos]=B;
		std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
		for(int i=1;i<=pos;++i) FA[t[i]]=t[i];
		for(int _=1;_<=k;++_)
		{
			int i=X[_],j=Y[_];
			for(int dir=0;dir<8;++dir)
			{
				int u=i+dx[dir],v=j+dy[dir];
				if(u>=0&&v>=0&&u<=n&&v<=m&&s[u][v]=='#') MERGE(val[i][j],val[u][v]);
			}
		}
		std::vector<int> v1,v2;
		for(int i=1;i<=pos;++i)
		{
			if(FIND(t[i])==FIND(A)) v1.pb(t[i]);
			if(FIND(t[i])==FIND(B)) v2.pb(t[i]);
		}
		bool flag=FIND(A)==FIND(B);
		for(auto a:v1) for(auto b:v2) flag=flag||*std::lower_bound(S+1,S+p+1,((ll)a<<32)|b)==(((ll)a<<32)|b);
		for(auto a:v2) for(auto b:v1) flag=flag||*std::lower_bound(S+1,S+p+1,((ll)a<<32)|b)==(((ll)a<<32)|b);
		for(int _=1;_<=k;++_) s[X[_]][Y[_]]='.';
		puts(flag?"NO":"YES");fflush(stdout);
	}
	return 0;
}