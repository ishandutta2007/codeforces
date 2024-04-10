#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,k,vst[200005],a[400005];
vector<int> g[200005];
void dfs(int x){
	vst[x]=1,a[++a[0]]=x;
	for(int y:g[x])if(!vst[y])dfs(y),a[++a[0]]=x;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1);
	for(int i=1;i<=k;i++){
		int l=(i-1)*((2*n+k-1)/k)+1,r=i*((2*n+k-1)/k);
		r=min(r,a[0]),l=min(l,a[0]);
		cout<<r-l+1<<' ';
		for(int j=l;j<=r;j++)cout<<a[j]<<' ';
		puts("");
	}
}