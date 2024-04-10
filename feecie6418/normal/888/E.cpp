#include<bits/stdc++.h>
using namespace std;
int n,m,a[40],b[40],ans=0;
vector<int> a1,a2;
void dfs(int x,int s){
	if(x>n/2)return a1.push_back(s);
	dfs(x+1,(s+a[x])%m),dfs(x+1,s);
}
void dfs2(int x,int s){
	if(x>n-n/2)return a2.push_back(s);
	dfs2(x+1,(s+b[x])%m),dfs2(x+1,s);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n/2;i++)cin>>a[i];
	for(int i=1;i<=n-n/2;i++)cin>>b[i];
	dfs(1,0),dfs2(1,0),sort(a1.begin(),a1.end()),sort(a2.begin(),a2.end());
	for(int i:a1){
		auto it=lower_bound(a2.begin(),a2.end(),m-i);
		if(it!=a2.begin())--it;
		ans=max(ans,max((i+*it)%m,(i+*--a2.end())%m));
	}
	cout<<ans;
}