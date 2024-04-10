//qwqwqwq
//gua
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 200020
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
int n,m,k,p[N],dis[N],nxt[N],ok[N],vis[N];
int cnt,head[N];
int qwq[N],mx,mn;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
int main(){
	
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(v,u);
	}
	k=read();
	for(int i=1;i<=k;i++){
		p[i]=read();
	}
	for(int i=1;i<k;i++){
		nxt[p[i]]=p[i+1];
	}
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(0,p[k]));
	dis[p[k]]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				qwq[v]=0;
				if(nxt[v]==u)ok[v]=1;
				else ok[v]=0;
				q.push(make_pair(dis[v],v));
			}
			else if(dis[v]==dis[u]+1){
				qwq[v]=1;
				if(nxt[v]==u)ok[v]=1;
			}
		}
	}
	for(int i=k-1;i>=1;i--){
		if(!ok[p[i]])++mn;
		if(qwq[p[i]]||!ok[p[i]])++mx;
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}