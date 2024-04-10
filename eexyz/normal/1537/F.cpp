#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<int>son[N];
long long c[4];
int f[N],i,n,T,m,fl,dep[N],v[N],t[N],s1,x,y,X[N],Y[N],cnt;
inline int find(int x){if(f[x]!=x)f[x]=find(f[x]);return f[x];}
void dfs(int now,int fat){
	dep[now]=dep[fat]+1;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat)dfs(T,now);
	}
}
int main(){
    ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		s1=0;
		for(i=1;i<=n;++i)cin>>v[i],v[i]+=1000000000,s1^=v[i],son[i].clear(),f[i]=i;
		for(i=1;i<=n;++i)cin>>t[i],t[i]+=1000000000,s1^=t[i];
		cnt=0;
		for(i=1;i<=m;++i){
			cin>>x>>y;
			if(find(x)==find(y)){
				X[++cnt]=x,Y[cnt]=y;
			}
			else f[find(x)]=find(y),son[x].push_back(y),son[y].push_back(x);
		}
		if(s1&1){
			cout<<"NO\n";continue;
		}
		dfs(1,0);fl=0;
		for(i=1;i<=cnt;++i){
			fl|=(dep[X[i]]&1)==(dep[Y[i]]&1);
		}
		if(fl)cout<<"YES\n";
		else{
			c[0]=c[1]=0;
			for(i=1;i<=n;++i){
				c[dep[i]&1]+=v[i]-t[i];
			}
			if(c[0]!=c[1])cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}