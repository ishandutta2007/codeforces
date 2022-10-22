#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n,m,cnt;
struct Edge{
	int to,next;
}e[MAXN<<2];
int head[MAXN],used[MAXN];
priority_queue<int,vector<int>, greater<int> > Q; 
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
inline void add(int u,int v){
	cnt++,e[cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	Q.push(1);used[1]=1;
	while(!Q.empty()){
		int u=Q.top();Q.pop();printf("%d ",u);
		for(int i=head[u];i;i=e[i].next){
			if(!used[e[i].to]) Q.push(e[i].to),used[e[i].to]=1;
		}
	}return 0;
}