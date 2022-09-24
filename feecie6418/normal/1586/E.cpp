#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,st[300005],top,cnt[300005],f[300005],X[300005],Y[300005];
vector<int> g[300005];
int gf(int x){
	return f[x]==x?x:f[x]=gf(f[x]);
}
void dfs(int x,int f,int to){
	st[++top]=x;
	if(x==to){
		cout<<top<<'\n';
		for(int i=1;i<=top;i++)cout<<st[i]<<' ';
		puts("");
	}
	for(int y:g[x])if(y^f)dfs(y,x,to);
	top--;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(gf(x)!=gf(y)){
			g[x].push_back(y),g[y].push_back(x);
			f[gf(x)]=gf(y);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d",&X[i],&Y[i]),cnt[X[i]]++,cnt[Y[i]]++;
	int sum=0;
	for(int i=1;i<=n;i++)if(cnt[i]&1)sum++;
	if(sum)return puts("NO"),cout<<sum/2<<'\n',0;
	puts("YES");
	for(int i=1;i<=q;i++)dfs(X[i],0,Y[i]);
}