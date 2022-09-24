#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c[1000010];
struct hori{
	int y,x1,x2;
}a[100005];
vector<int> q[1000010];
vector<pair<int,int> > q2[1000010];
ll ans=0;
void U(int x,int k){
	x++;
	while(x<=1000005)c[x]+=k,x+=x&-x;
}
ll Q(int x){
	x++;
	ll r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
int main() {
	cin>>n>>m;
	for(int i=1,u,v,w;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w),a[i]={u,v,w},q[v].push_back(u),q[w+1].push_back(-u);
		if(v==0&&w==1000000)ans++;
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w),q2[u].push_back(make_pair(v,w));
		if(v==0&&w==1000000)ans++;
	}
	for(int i=0;i<=1000000;i++){
		for(int j:q[i])if(j<0)U(-j,-1);else U(j,1);
		for(pair<int,int> j:q2[i])ans+=Q(j.second)-Q(j.first-1);
	}
	cout<<ans+1;
	return 0;
}