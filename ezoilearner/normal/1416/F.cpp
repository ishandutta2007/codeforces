#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
typedef long long ll;
typedef pair<int,int> pii;
#define rez resize
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 100010
#define E 400010
#define cout cerr
#define FR first
#define SE second
vector<int> a[Maxn];
int head[Maxn],v[E<<1],nxt[E<<1],w[E<<1],tot=0,deg[Maxn];
int S,T,_S,_T;
int nx[4]={-1,1,0,0};
int ny[4]={0,0,-1,1};
char opt[4]={'U','D','L','R'};
inline void add_edge(int s,int e,int t){
	tot++;v[tot]=e;w[tot]=t;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;w[tot]=0;nxt[tot]=head[e];head[e]=tot;
}
int to[Maxn],val[Maxn];
int id(int i,int j){return (i-1)*m+j;}
void output(int t){
	int i=(t+m-1)/m,j=t%m;
	if(!j)j=m;
	int h1=(to[t]+m-1)/m,h2=to[t]%m;if(!h2)h2=m;
	rep(k,0,3)
		if(i+nx[k]==h1&&j+ny[k]==h2){
			putchar(opt[k]);
			break;
		}
	putchar(' ');
}

int cur[Maxn],edge[E],len;
int Q[Maxn],hd,tl,d[Maxn];
bool Bfs(){
	rep(i,0,tl-1)d[Q[i]]=-1;
	d[S]=0;
	hd=tl=0;Q[tl++]=S;
	while(hd<tl){
		int u=Q[hd];hd++;
		for(int i=head[u];i;i=nxt[i])
			if(w[i]&&d[v[i]]<0){
				d[v[i]]=d[u]+1;
				Q[tl++]=v[i];
				if(v[i]==T)return true;
			}
	}
	return false;
}
int find(int u,int flow){
	if(u==T||!flow)return flow;
	int res=0,minv;
	for(int &i=head[u];i;i=nxt[i])
		if(w[i]&&d[v[i]]==d[u]+1&&(minv=find(v[i],min(flow,w[i])))){
			w[i]-=minv;
			if(i&1)w[i+1]+=minv;
			else w[i-1]+=minv;
			res+=minv;
			flow-=minv;
			if(!flow)break;
		}
	return res;
}

void init(){
	tot=0;memset(head,0,sizeof(int)*(T+1));
	memset(deg,0,sizeof(int)*(T+1));len=0;
	memset(to,0,sizeof(int)*(n*m+1));
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int Task;rd(Task);
	while(Task--){
		rd(n);rd(m);
		rep(i,1,n){
			a[i].rez(m+1);
			rep(j,1,m)rd(a[i][j]);
		}
		init();
		if(n==1&&m==1){
			puts("NO");
			continue;
		}
		_S=n*m+1;_T=n*m+2;
		rep(i,1,n)
			rep(j,1,m){
				bool flag=true;
				rep(k,0,3)
					if(i+nx[k]>=1&&i+nx[k]<=n&&j+ny[k]>=1&&j+ny[k]<=m){
						if(a[i+nx[k]][j+ny[k]]<a[i][j])flag=false;
						if(a[i+nx[k]][j+ny[k]]==a[i][j]&&((i+j)&1)){
							add_edge(id(i,j),id(i+nx[k],j+ny[k]),1);
							edge[++len]=tot-1;
						}
					}
				if(flag){
					if((i+j)&1){
						deg[_S]++;deg[id(i,j)]--;
					}else{
						deg[id(i,j)]++;deg[_T]--;
					}
				}else{
					if((i+j)&1)add_edge(_S,id(i,j),1);
					else add_edge(id(i,j),_T,1);
				}
			}
		add_edge(_T,_S,n*m);
		S=_T+1;T=_T+2;int sum=0;
		rep(i,1,_T)
			if(deg[i]>0)add_edge(i,T,deg[i]),sum+=deg[i];
			else if(deg[i]<0)add_edge(S,i,-deg[i]);
		memset(d,-1,sizeof(int)*(T+1));
		memcpy(cur,head,sizeof(int)*(T+1));
		int ans=0;
		while(Bfs()){
			ans+=find(S,inf);
			memcpy(head,cur,sizeof(int)*(T+1));
		}
		if(ans<sum){
			puts("NO");
			continue;
		}else{
			puts("YES");
			rep(i,1,len)
				if(w[edge[i]]==0){
					int t=edge[i];
					to[v[t]]=v[t+1];
					to[v[t+1]]=v[t];
					int x=(v[t]+m-1)/m,y=v[t]%m;if(!y)y=m;
					val[v[t]]=a[x][y]/2;val[v[t+1]]=(a[x][y]+1)/2;
				}
			rep(i,1,n)
				rep(j,1,m)
					if(!to[id(i,j)]){
						int t=id(i,j);
						rep(k,0,3)
							if(i+nx[k]>=1&&i+nx[k]<=n&&j+ny[k]>=1&&j+ny[k]<=m&&a[i+nx[k]][j+ny[k]]<a[i][j]){
								to[t]=id(i+nx[k],j+ny[k]);
								val[t]=a[i][j]-a[i+nx[k]][j+ny[k]];
								break;
							}
					}
			rep(i,1,n){
				rep(j,1,m)printf("%d ",val[id(i,j)]);
				puts("");
			}
			rep(i,1,n){
				rep(j,1,m)output(id(i,j));
				puts("");
			}
		}
	}
	return 0;
}