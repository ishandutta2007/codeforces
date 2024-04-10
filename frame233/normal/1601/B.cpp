#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,NC=N*22;
int a[N],b[N],f[N][20],nc;
struct edge{int v,nxt,w;}c[NC*3];
int front[NC],ec,Log2[N];
inline void addedge(int u,int v,int w){c[++ec]=(edge){v,front[u],w},front[u]=ec;}
int dis[NC],pre[NC];
struct node{int u,d;inline bool operator < (const node &o)const{return d>o.d;}};
std::priority_queue<node> q;
std::set<int> S[N];
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]),b[i]+=i,f[i][0]=b[i],S[b[i]].insert(i);
	nc=n;
	for(int i=n;i>=1;--i){
		for(int j=1;j<20&&i+(1<<(j-1))<=n;++j){
			f[i][j]=++nc,addedge(f[i][j-1],nc,0),addedge(f[i+(1<<(j-1))][j-1],nc,0);
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;++i){
		if(a[i]>=i)addedge(0,i,1);
		else{
			int l=i-a[i],r=i,k=Log2[r-l+1];
			addedge(f[l][k],i,1),addedge(f[r-(1<<k)+1][k],i,1);
		}
	}
	dis[0]=0,q.push({0,0});
	while(!q.empty()){
		node x=q.top();q.pop();if(dis[x.u]!=x.d)continue;
		for(int i=front[x.u];i;i=c[i].nxt){
			int v=c[i].v;
			if(dis[v]>dis[x.u]+c[i].w){
				pre[v]=x.u,dis[v]=dis[x.u]+c[i].w,q.push({v,dis[v]});
			}
		}
	}
	printf("%d\n",dis[n]>=1e9?-1:dis[n]);
	if(dis[n]<1e9){
		std::vector<int> v;int last=n;
		for(int i=pre[n];i;i=pre[i]){
			if(i<=n){
				int l=last-a[last],r=last;
				auto it=S[i].lower_bound(l);
				assert(*it<=r);
				printf("%d ",*it),last=i;
			}
		}
		printf("0\n");
	}
	return 0;
}