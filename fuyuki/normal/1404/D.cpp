#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e6+1;
vector<int>e[N];
int n,m,sum,tag[N],a[N],id[N];
V check(int&x){x-=m,x+=x>>31&m;}
V first(){
	cout<<"First"<<endl;
	FOR(i,1,m)cout<<i%n+1<<' ';
}
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs(int u,int p=0){
	if(tag[u]=p)check(sum+=u);
	for(int v:e[u])if(!~tag[v])dfs(v,p^1);
}
V second(){
	cout<<"Second"<<endl;
	FOR(i,1,m)tag[i]=-1;
	FOR(i,1,m)
		if(!id[scanf("%d",a+i),a[i]])id[a[i]]=i;
		else add_edge(id[a[i]],i);
	FOR(i,1,n)add_edge(i,i+n);
	FOR(i,1,m)if(!~tag[i])dfs(i,1);
	if(sum)FOR(i,1,m)tag[i]^=1;
	FOR(i,1,m)if(tag[i])cout<<i<<' ';
}
int main(){scanf("%d",&n),m=n<<1,n%2==0?first():second();}