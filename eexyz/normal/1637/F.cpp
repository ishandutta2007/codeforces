#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define int long long
vector<int>son[N];
int a[N],res,ans,mx,n,i,x,y,f1[N],f2[N],down[N],up[N],f3[N];
void dfs(int now,int fat){
	for(int T,V,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);V=max(f1[T],a[T]);
			if(V>f1[now])f2[now]=f1[now],f1[now]=V;else f2[now]=max(f2[now],V);
		}
	}
	down[now]=max(down[now],a[now]-f1[now]);
} 
void dfs_(int now,int fat){
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			f3[T]=max(f3[now],(f1[now]==max(f1[T],a[T])?f2[now]:f1[now]));
			up[T]=max(up[T],a[now]-f3[T]);
			f3[T]=max(f3[T],a[now]);
			dfs_(T,now);
		}
	}
}
void DFS(int now,int fat){
	up[now]+=up[fat];
	for(int T,i=0;i<son[now].size();++i){
		if((son[now][i])!=fat)DFS(son[now][i],now);
	}
	if(son[now].size()==1){
		res=min(res,up[now]+mx+(a[now]==mx?mx-f3[now]:0));
	}
}
signed main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],mx=max(mx,a[i]);
	for(i=1;i<n;++i)cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
	if(n==2)cout<<(max(a[1],a[2])*2)<<"\n";
	else{
		int rt=0;
		for(i=1;i<=n;++i)if(son[i].size()>1)rt=i;
		dfs(rt,0);dfs_(rt,0);
//		for(i=1;i<=n;++i)cout<<up[i]<<" "<<down[i]<<" "<<f1[i]<<" "<<f2[i]<<" "<<f3[i]<<"\n";
		for(i=1;i<=n;++i)ans+=down[i],up[i]-=down[i];//up[rt]=0;
		res=1e18;DFS(rt,0);
		cout<<ans+res;
	}
}