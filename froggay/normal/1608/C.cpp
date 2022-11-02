#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
bool ans[N];
int n,a[N],b[N],pa[N],pb[N],vis[N];
set<int> A,B;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		vis[i]=0;
		pa[i]=i;
		ans[i]=0;
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		pb[i]=i;
	}
	sort(pa+1,pa+n+1,[&](int i,int j){return a[i]<a[j];});
	sort(pb+1,pb+n+1,[&](int i,int j){return b[i]<b[j];});
	queue<int> q;
	q.push(pa[n]);
	if(pa[n]^pb[n])q.push(pb[n]);
	vis[pa[n]]=vis[pb[n]]=1;
	int i=n,j=n;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[u]=1;
		while(i>=1&&a[pa[i]]>a[u]){
			if(!vis[pa[i]])q.push(pa[i]),vis[pa[i]]=1;
			--i;
		}
		while(j>=1&&b[pb[j]]>b[u]){
			if(!vis[pb[j]])q.push(pb[j]),vis[pb[j]]=1;
			--j;
		}
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i];
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}