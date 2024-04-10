#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,vst[300005];
deque<int> ans,ans2;
ll a[300005],sum=0,X;
struct E{
	int to,id;
};
vector<E> g[300005];
void dfs(int x){
	vst[x]=1;
	for(E i:g[x]){
		int y=i.to;
		if(vst[y])continue;
		dfs(y);
		if(a[x]+a[y]>=X)ans.push_back(i.id),a[x]+=a[y]-X;
		else ans2.push_front(i.id);
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&X);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
	if(sum<(n-1)*X)return puts("NO"),0;
	puts("YES");
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g[x].push_back({y,i}),g[y].push_back({x,i});
	dfs(1);
	for(int i:ans)cout<<i<<'\n';
	for(int i:ans2)cout<<i<<'\n';
}