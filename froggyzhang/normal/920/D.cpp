#include<bits/stdc++.h>
using namespace std;
#define N 5050
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,K,a[N],V,sum;
bool dp[N][N];
vector<int> T;
void dfs(int u,int s){
	if(!u)return;
	if(dp[u-1][s])dfs(u-1,s);
	else T.push_back(u),dfs(u-1,((s-a[u])%K+K)%K);	
}
void Move(int cnt,int x,int y){
	if(!cnt)return;
	cout<<cnt<<' '<<x<<' '<<y<<'\n';
	int t=min(1LL*cnt*K,(ll)a[x]);
	a[x]-=t,a[y]+=t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K>>V;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<V){
		cout<<"NO\n";
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		for(int j=0;j<K;++j){
			dp[i][j]|=dp[i-1][((j-a[i])%K+K)%K];	
		}
	}
	if(!dp[n][V%K]){
		cout<<"NO\n";
		return 0;
	}
	dfs(n,V%K);
	cout<<"YES\n";
	if(T.empty()){
		Move(1e9,1,2);
		T.push_back(1);
	}
	for(int i=1;i<(int)T.size();++i){
		Move(1e9,T[i],T[0]);
	}
	int jb=T[0]==1?2:1;
	for(int i=1;i<=n;++i){
		if(i==jb||i==T[0])continue;
		if(a[i])Move(1e9,i,jb);
	}
	if(a[T[0]]>V)Move((a[T[0]]-V)/K,T[0],jb);
	if(a[T[0]]<V)Move((V-a[T[0]])/K,jb,T[0]);
	return 0;
}