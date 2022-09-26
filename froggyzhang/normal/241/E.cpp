#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 5050
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m; 
int e_cnt=0,head[N],cnt[N],dis[N],vis[N];
int u[N],v[N],mp1[N][N],mp2[N][N],vis1[N],vis2[N];
bool ok[N];
queue<int> q;
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	e_cnt++;
	edge[e_cnt].to=b;
	edge[e_cnt].nxt=head[a];
	edge[e_cnt].val=c;
	head[a]=e_cnt;
}
bool SPFA(int s){
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]<dis[u]+edge[i].val){
				dis[v]=dis[u]+edge[i].val;
				if(!vis[v]){
					vis[v]=1;
					cnt[v]++;
					q.push(v);
				}
				if(cnt[v]>n)return true;
			}
		}
	}
	return false;
}
void dfs1(int u){
	for(int i=1;i<=n;i++){
		if(u==i)continue;
		if(mp1[u][i]){
			mp1[u][i]=0;
			vis1[i]=1;
			dfs1(i);
		}
	
	}
}
void dfs2(int u){
	for(int i=1;i<=n;i++){
		if(u==i)continue;
		if(mp2[u][i]){
			mp2[u][i]=0;
			vis2[i]=1;
			dfs2(i);
		}
	
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		u[i]=read(),v[i]=read();
		mp1[u[i]][v[i]]=1;
		mp2[v[i]][u[i]]=1;
	}
	dfs1(1);
	dfs2(n); 
	for(int i=1;i<=n;i++){
		if(vis1[i]&&vis2[i])ok[i]=true;
	}
	ok[1]=ok[n]=true;
	for(int i=1;i<=m;i++){
		if(ok[u[i]]&&ok[v[i]]){
			add(u[i],v[i],1);
			add(v[i],u[i],-2);
		}
	}
	if(SPFA(1)){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
		for(int i=1;i<=m;i++){
			if(ok[u[i]]&&ok[v[i]]){
				cout<<dis[v[i]]-dis[u[i]]<<endl;
			}
			else{
				puts("1");
			}
		}
	}
	return 0;
}