#include<bits/stdc++.h>
using namespace std;
#define N 1005
int n,i,ans,x,zz,q,to[10][10],v[109905];
char s[N],t[N];
void cal(){
	zz=to[v[1]][v[2]];
	if(!zz)return ;
	for(int i=3;i<=n;++i){
		zz=to[zz-1][v[i]];
		if(!zz)return ;
	}
	if(zz==1)++ans;
}
void dfs(int now){
	if(now>n){
		return cal();
	}
	for(int i=0;i<6;++i)v[now]=i,dfs(now+1);
}
int main(){
	cin>>n>>q;
	for(i=1;i<=q;++i)scanf("%s%s",s+1,t+1),to[s[1]-'a'][s[2]-'a']=t[1]-'a'+1;
	dfs(1);cout<<ans;
}