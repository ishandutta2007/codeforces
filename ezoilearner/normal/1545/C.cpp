#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n;
#define Maxn 505
int p[Maxn<<1][Maxn];
vector<int> vec[Maxn][Maxn];
int cnt[Maxn][Maxn];
int col[Maxn<<1];
int Q[Maxn<<1],hd,tl;

const int Mod=998244353;
int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}

int head[Maxn<<1],v[500010],nxt[500010],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

void dfs(int u){
	for(int i=head[u];i;i=nxt[i])
		if(col[v[i]]==-1){
			col[v[i]]=col[u]^1;
			dfs(v[i]);
		}
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		tot=0;
		memset(head,0,sizeof(int)*(2*n+1));
		rep(i,1,n)
			rep(j,1,n)vec[i][j].clear();
		rep(i,1,2*n)
			rep(j,1,n){
				rd(p[i][j]);
				vec[j][p[i][j]].push_back(i);
			}
		rep(i,1,2*n)col[i]=-1;
		hd=tl=0;
		rep(i,1,n)
			rep(j,1,n){
				cnt[i][j]=vec[i][j].size();
				if(cnt[i][j]==1){
					if(col[vec[i][j][0]]==-1){
						col[vec[i][j][0]]=1;
						Q[tl++]=vec[i][j][0];
					}
				}
			}
		while(hd<tl){
			int u=Q[hd];hd++;
			if(col[u]==1){
				rep(i,1,n){
					vector<int> &A=vec[i][p[u][i]];
					for(int j=0;j<A.size();++j)
						if(col[A[j]]==-1){
							col[A[j]]=0;
							Q[tl++]=A[j];
						}
				}
			}else{
				rep(i,1,n){
					cnt[i][p[u][i]]--;
					if(cnt[i][p[u][i]]==1){
						vector<int> &A=vec[i][p[u][i]];
					for(int j=0;j<A.size();++j)
						if(col[A[j]]==-1){
							col[A[j]]=1;
							Q[tl++]=A[j];
						}
					}
				}
			}
		}
		rep(i,1,n)
			rep(j,1,n)
				if(cnt[i][j]==2){
					int s=-1;
					for(int k=0;k<vec[i][j].size();++k){
						int p=vec[i][j][k];
						if(col[p]==-1){
						if(s==-1)s=p;
						else{
							add_edge(s,p);
							break;
						}
						}
					}
				}
		int res=1;
		rep(u,1,2*n)
			if(col[u]==-1){
				res=add(res,res);
				col[u]=1;dfs(u);
			}
		printf("%d\n",res);
		rep(i,1,2*n)
			if(col[i]==1)printf("%d ",i);
		puts("");
	}
	return 0;
}