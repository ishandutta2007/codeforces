#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,is[500005],b[500005];
vector<int> g[500005];
struct P{
	int id,x;
}a[500005];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]={i,x};
	sort(a+1,a+n+1,[](P o,P oo){return o.x<oo.x;});
	for(int i=1;i<=n;i++){
		for(int y:g[a[i].id])is[b[y]]=1;
		int j=1;
		while(is[j])j++;
		b[a[i].id]=j;
		if(b[a[i].id]!=a[i].x)return puts("-1"),0;
		for(int y:g[a[i].id])is[b[y]]=0;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i].id);
}