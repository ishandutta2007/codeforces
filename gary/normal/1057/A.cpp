#include<bits/stdc++.h>
using namespace std;
int n,up[200005];
void dfs(int now){
	if(now!=1) dfs(up[now]);
	cout<<now<<" ";
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++) cin>>up[i];
	dfs(n);
	return 0;
}