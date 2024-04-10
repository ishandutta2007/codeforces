#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int f[N],dep[N],fa[N],d[N];
vector<int>son[N];
inline int find(int x){if(f[x]!=x)f[x]=find(f[x]);return f[x];}
void dfs(int now,int fat){
	dep[now]=dep[fat]+1;fa[now]=fat;
	for(int i=0;i<son[now].size();++i){
		if((son[now][i]!=fat))dfs(son[now][i],now);
	}
}
int len(int x,int y){
//	cout<<x<<" "<<y<<"\n";
	if(x==y)return 0;
	if(dep[x]>dep[y])return len(fa[x],y)+1;
	return len(x,fa[y])+1;
}
void CAL(int x,int y){
	if(x==y){cout<<x<<" ";return ;}
	if(dep[x]>dep[y]){
		cout<<x<<" ",CAL(fa[x],y);
	}
	else{
		CAL(x,fa[y]);cout<<y<<" ";
	}
}
int n,m,i,q,gg,x[N],y[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;++i)f[i]=i;
	for(i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		if(find(x[i])!=find(y[i])){
			son[x[i]].push_back(y[i]);
			son[y[i]].push_back(x[i]);
			f[find(x[i])]=find(y[i]);
		}
	}
	dfs(1,0);
	cin>>q;
	for(i=1;i<=q;++i){
		cin>>x[i]>>y[i];
		d[x[i]]^=1;
		d[y[i]]^=1;
	}
	for(i=1;i<=n;++i){
		if(d[i])++gg;
	}
	if(gg){
		cout<<"NO\n"<<(gg>>1); return 0;
	}
	cout<<"YES\n";
	for(i=1;i<=q;++i){
		cout<<len(x[i],y[i])+1<<"\n";
		CAL(x[i],y[i]);cout<<"\n";
	}
}