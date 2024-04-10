#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,ans=0;
set<int> s[200005];
bool is(int x){
	return !s[x].size()||(s[x].size()&&*--s[x].end()<x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		s[u].insert(v),s[v].insert(u);
	}
	for(int i=1;i<=n;i++)if(is(i))ans++;
	scanf("%d",&q);
	for(int i=1,opt,x,y;i<=q;i++){
		scanf("%d",&opt);
		if(opt==3){
			printf("%d\n",ans);
			continue;
		}
		scanf("%d%d",&x,&y);
		ans-=is(x),ans-=is(y);
		if(opt==1)s[x].insert(y),s[y].insert(x);
		if(opt==2)s[x].erase(y),s[y].erase(x);
		ans+=is(x),ans+=is(y);
	}
}