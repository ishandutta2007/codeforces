#include<bits/stdc++.h>
using namespace std;
int n,m,fa[200005],d[200005],st[200005],top,tmp[200005];
pair<int,int> v[200005];
vector<int> g[200005],h[200005],p;
void dfs(int x,int fa,int to){
	st[++top]=x;
	if(x==to)for(int i=1;i<=top;i++)tmp[st[i]]=1;
	for(int y:h[x])if(y^fa)dfs(y,x,to);
	top--;
}
void dfs2(int x,int fa,int to,int &e,int &f){
	st[++top]=x;
	if(x==to){
		e=1,f=top;
		while(!tmp[st[e]])e++;
		while(!tmp[st[f]])f--;
		printf("%d ",f-e+1);
		for(int i=e;i<=f;i++)printf("%d ",st[i]);
		puts(""),e=st[e],f=st[f];
	}
	for(int y:h[x])if(y^fa)dfs2(y,x,to,e,f);
	top--;
}
void find(int x,int fa,int to){
	st[++top]=x;
	if(x==to)for(int i=1;i<=top;i++)p.push_back(st[i]);
	for(int y:h[x])if(y^fa)find(y,x,to);
	top--;
}
void Print(int a,int b,int c,int d){
	int e,f;
	for(int i=1;i<=n;i++)if(fa[i])h[fa[i]].push_back(i),h[i].push_back(fa[i]);
	dfs(a,0,b),puts("YES"),dfs2(c,0,d,e,f);
	find(e,0,a),find(b,0,f);
	cout<<p.size()<<' ';
	for(int i:p)cout<<i<<' ';
	p.clear(),find(e,0,c),find(d,0,f),printf("\n%d ",p.size());
	for(int i:p)cout<<i<<' ';
	exit(0);
}
void dfs(int x,int f){
	fa[x]=f,d[x]=d[f]+1;
	for(int y:g[x]){
		if(y==f)continue;
		if(!d[y])dfs(y,x);
		else if(d[y]<d[x]){
			int p=x,q=y,a=0,b=0;
			while(p!=q){
				if(d[p]<d[q])swap(p,q);
				if(v[p].first)a=v[p].first,b=v[p].second;
				v[p]=make_pair(x,y),p=fa[p];
			}
			if(a)Print(x,y,a,b);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++){
		if(d[i])continue;
		dfs(i,0);
	}
	puts("NO");
}