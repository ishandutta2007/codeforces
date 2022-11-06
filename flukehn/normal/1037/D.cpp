#include<bits/stdc++.h>
using namespace std;
#define SZ(x) ((x).size())
const int N=2e5+11;
vector<int> g[N];
int n,r[N],a[N],d[N];
int cmp(int i,int j){
	return r[i]<r[j];
}
int q[N],h,t,s[N];
void bfs(int x){
	d[q[h=t=1]=x]=1;
	int i,y;
	while(h<=t){
		x=q[h++];
		for(i=0;i<SZ(g[x]);++i)
			if(!d[y=g[x][i]]){
				d[y]=d[x]+1;
				q[++t]=y;
			}
	}
}


int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n;
	int i,x,y,z,l;
	for(i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;++i)
		scanf("%d",a+i),r[a[i]]=i;
	for(i=1;i<=n;++i)
		sort(g[i].begin(),g[i].end(),cmp);
	bfs(1);
	//for(i=1;i<=n;++i)cerr<<a[i]<<" \n"[i==n];
	//for(i=1;i<=n;++i)cerr<<q[i]<<" \n"[i==n];
	for(i=1;i<=n;++i)
		if(a[i]^q[i])return puts("No"),0;
	puts("Yes");
}