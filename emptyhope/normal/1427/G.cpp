#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
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

#define N 205
#define maxn (N*N)
int a[N][N],n;
struct edge{
	int to,nxt,w,fl;
}e[maxn<<2];
int head[maxn],tot=1;
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u],1,0};
	head[u]=tot;
}
inline void add(int u,int v){adde(u,v),adde(v,u);}

#define P(i,j) (((i)-1)*n+(j))
pii b[maxn];
bool S[maxn],T[maxn];
bool vis[maxn];

int k;

bool push(int u,int now)
{
	if(S[u]&&now==-1)return 1;
	if(T[u]&&now==1)return 1;
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if((now==1&&e[i].fl==1) || (now==-1&&e[i].fl!=-1) || vis[v])continue;
		if(push(v,now)){
			e[i].fl++,e[i^1].fl--;
			return 1;
		}
	}
	return 0;
}

signed main()
{
	n=read();
	For(i,1,n)For(j,1,n)a[i][j]=read();
	For(i,1,n)For(j,1,n)if(a[i][j]>=0){
		int u=P(i,j);
		if(i+1<=n&&a[i+1][j]>=0) add(u,P(i+1,j));
		if(j+1<=n&&a[i][j+1]>=0) add(u,P(i,j+1));
		if(a[i][j]){
			T[u]=1;
			b[++k]=mkp(a[i][j],u);
		}
	}
	sort(b+1,b+k+1);
	int flow=0,res=0;
	For(i,1,k-1){
		int u=b[i].se;
		memset(vis,0,sizeof vis);
		while(push(u,-1)) flow--,memset(vis,0,sizeof vis);
		T[u]=0,S[u]=1,memset(vis,0,sizeof vis);
		For(j,1,i)
			if(!vis[b[j].se]) {
				while(push(b[j].se,1))
					flow++,memset(vis,0,sizeof vis); 
			}
	//	cout<<flow<<endl;
		res+=flow*(b[i+1].fi-b[i].fi);
	}
	cout<<res;
	return 0;
}