#include<bits/stdc++.h>
using namespace std;
int n,m,p[1<<22],vst[1<<23],ans=0;
void dfs(int x){
	if(vst[x])return ;
	vst[x]=1;
	if(x<(1<<n)){
		if(p[x])dfs(x+(1<<n));
		for(int i=0;i<n;i++)if(x&(1<<i))dfs(x-(1<<i));
	}
	else dfs((1<<n+1)-1-x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<m;i++)scanf("%d",&x),p[x]=i+1;
	for(int i=0;i<(1<<n);i++)if(p[i]&&!vst[i+(1<<n)])dfs(i+(1<<n)),ans++;
	cout<<ans;
}