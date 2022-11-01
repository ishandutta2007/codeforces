#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 2333
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
int n,head[N],cnt,d[N],vis[N],qwq,las;
struct Edge{
	int to,nxt;
}edge[N<<1]; 
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
queue<int> q;
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			q.push(i);
		}
	} 
	while(!q.empty()){
		int u=q.front();
		las=u;
		q.pop();
		vis[u]=1;
		if(!qwq)qwq=u;
		else{
			printf("? %d %d\n",qwq,u);
			cout.flush();
			int x=read();
			if(x==qwq){
				printf("! %d\n",qwq);
				cout.flush();
				return 0;
			}
			else if(x==u){
				printf("! %d\n",u);
				cout.flush();
				return 0;
			}
			qwq=0;
		}
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v])continue;
			--d[v];
			if(d[v]==1)q.push(v);
		}
	}
	printf("! %d\n",las);
	return 0;
}