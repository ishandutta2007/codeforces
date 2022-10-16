#include<bits/stdc++.h>
using namespace std;
#define N 10005
int n,m,yz[N],sz[N],p,i;
vector<int>son[10005];
void dfs(int now,int fat){
	if(son[now].size()==0)yz[now]=1;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);
			if(yz[T])++sz[now];
		}
	}
}
int main(){
	cin>>n;
	for(i=2;i<=n;++i)cin>>p,son[p].push_back(i);
	dfs(1,0);
	for(i=1;i<=n;++i){
		if(yz[i]||sz[i]>2);
		else return cout<<"No",0;
	}
	cout<<"Yes";
}