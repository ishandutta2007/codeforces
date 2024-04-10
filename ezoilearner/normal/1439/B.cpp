#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,K;
#define Maxn 100010 
#define cout cerr
#define FR first
#define SE second
int seq[Maxn],deg[Maxn];
int dfn[Maxn],dfk=0;
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
priority_queue<pii> Q;
bool vis[Maxn],hh[Maxn];

unordered_set<int> st[Maxn];

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
	int T;rd(T);
	while(T--){
		rd(n);rd(m);rd(K);
		for(int i=1;i<=n;++i)st[i].clear();
		tot=0;
		memset(head,0,sizeof(int)*(n+1));
		memset(vis,false,sizeof(bool)*(n+1));
		memset(deg,0,sizeof(int)*(n+1));
		int s,e;
		for(int i=1;i<=m;++i){
			rd(s);rd(e);
			st[s].insert(e);st[e].insert(s);
			deg[s]++;deg[e]++;
			add_edge(s,e);
		}
		while(!Q.empty())Q.pop();
		for(int i=1;i<=n;++i)
			if(deg[i]<K-1)Q.push(pii(-deg[i],i));
		while(!Q.empty()){
			pii x=Q.top();Q.pop();
			if(vis[x.SE])continue;
			vis[x.SE]=true;
			for(int i=head[x.SE];i;i=nxt[i])
				if(!vis[v[i]]){
					deg[v[i]]--;
					if(deg[v[i]]<K-1)Q.push(pii(-deg[v[i]],v[i]));	
				}
		}
		m=0;
		for(int i=1;i<=n;++i)
			if(!vis[i]){
				hh[i]=false;
				m+=deg[i];
				if(deg[i]<K)Q.push(pii(-deg[i],i));
			}
		m>>=1;
		int dfk=0;
		while(!Q.empty()){
			pii x=Q.top();Q.pop();
			if(hh[x.SE])continue;
			dfn[x.SE]=++dfk;
			hh[x.SE]=true;
			for(int i=head[x.SE];i;i=nxt[i])
				if(!vis[v[i]]&&!hh[v[i]]){
					deg[v[i]]--;
					if(deg[v[i]]<K)Q.push(pii(-deg[v[i]],v[i]));
				}
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(!hh[i]&&!vis[i])seq[++cnt]=i;
		if(cnt){
			printf("1 %d\n",cnt);
			for(int i=1;i<=cnt;++i)printf("%d ",seq[i]);
			puts("");
		}else{
		if(1ll*K*(K-1)/2>m){
			puts("-1");
		}else{
			bool flag=true;
			for(int i=1;i<=n&&flag;++i)
				if(!vis[i]){
					int sz=0;
					for(int j=head[i];j;j=nxt[j])
						if(!vis[v[j]]&&dfn[i]<dfn[v[j]])seq[++sz]=v[j];
				if(sz==K-1){
					bool D=true;
					for(int j=1;j<sz&&D;++j)
						for(int k=j+1;k<=sz;++k)
							if(!st[seq[j]].count(seq[k])){
								D=false;
								break;
							}
					if(D){
						puts("2");
						flag=false;
						printf("%d ",i);
						for(int j=1;j<=sz;++j)printf("%d ",seq[j]);
						puts("");
						break;
					}
				}
			}
			if(flag){
				puts("-1");
			}
		}
	}
	}
	return 0;
}