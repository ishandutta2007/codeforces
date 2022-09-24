#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
struct Thing{
	int a,b,id;
}a[100005];
int n,low[100005],dfn[100005],sign,bel[100005],SCC,ins[100005],st[100005],top;
vector<int> g[100005];
void dfs(int x){
	st[++top]=x,ins[x]=1,low[x]=dfn[x]=++sign;
	for(int y:g[x]){
		if(!dfn[y])dfs(y),low[x]=min(low[x],low[y]);
		else if(ins[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]^dfn[x])return ;
	SCC++;
	int tmp;
	do bel[tmp=st[top--]]=SCC,ins[tmp]=0; while(tmp!=x);
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].a),a[i].id=i;
	for(int i=1;i<=n;i++)scanf("%d",&a[i].b);
	sort(a+1,a+n+1,[](Thing x,Thing y){return x.a<y.a;});
	for(int i=2;i<=n;i++)g[a[i].id].push_back(a[i-1].id);
	sort(a+1,a+n+1,[](Thing x,Thing y){return x.b<y.b;});
	for(int i=2;i<=n;i++)g[a[i].id].push_back(a[i-1].id);
	dfs(a[n].id);
	for(int i=1;i<=n;i++)if(bel[i]==SCC)cout<<1;else cout<<0;
	puts("");
	for(int i=1;i<=n;i++){
		a[i]={0,0,0};
		low[i]=dfn[i]=bel[i]=ins[i]=st[i]=0;
		g[i].clear();
		sign=SCC=top=0;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}