#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],p,d[200005],dfn[200005],sign;
int c[200005],dd[200005],qq;
vector<int> g[200005];
void Clear(){
	p=qq=sign=0;
	for(int i=1;i<=n;i++){
		d[i]=dfn[i]=0;
		g[i].clear();
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1,t,x,y;i<=m;i++){
			scanf("%d%d%d",&t,&x,&y);
			if(!t)a[++p]=x,b[p]=y;
			else g[x].push_back(y),d[y]++,c[++qq]=x,dd[qq]=y;
		}
		queue<int> q;
		for(int i=1;i<=n;i++)if(!d[i])q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop(),dfn[x]=++sign;
			for(int y:g[x]){
				d[y]--;
				if(!d[y])q.push(y);
			}
		}
		bool flag=0;
		for(int i=1;i<=n;i++)if(!dfn[i])flag=1;
		if(flag){
			puts("NO");
			Clear();
			continue;
		}
		puts("YES");
		for(int i=1;i<=p;i++){
			if(dfn[a[i]]<dfn[b[i]])printf("%d %d\n",a[i],b[i]);
			else printf("%d %d\n",b[i],a[i]);
		}
		for(int i=1;i<=qq;i++){
			printf("%d %d\n",c[i],dd[i]);
		}
		Clear();
	}
	return 0;
}