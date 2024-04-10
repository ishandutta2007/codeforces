#include<bits/stdc++.h>
using namespace std;
#define N 16
#define M 2005
typedef long long ll;
typedef pair<int,int> pii;
bitset<M> dp[1<<N];
int n,k,a[N],b[N];
void dfs(int u,int x){
	if(!u)return;
	for(int i=0;i<n;++i){
		if(u>>i&1){
			for(int y=x,t=0;y<=2000&&dp[u][y];y*=k,++t){
				if(y>a[i]&&dp[u^(1<<i)][y-a[i]]){
					dfs(u^(1<<i),y-a[i]);
					for(int j=0;j<n;++j){
						if(u>>j&1)b[j]+=t;
					}
					return;
				}
			}	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);++i){
		for(int j=0;j<n;++j){
			if(i>>j&1){
				dp[i]|=dp[i^(1<<j)]<<a[j];
			}
		}
		for(int z=2000/k;z>=1;--z){
			if(dp[i][z*k])dp[i][z]=1;
		}
	}
	if(!dp[(1<<n)-1][1]){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	dfs((1<<n)-1,1);
	priority_queue<pii> q;
	for(int i=0;i<n;++i){
		q.emplace(b[i],a[i]);
	}	
	while(q.size()>1){
		auto [t1,x]=q.top();
		q.pop();
		auto [t2,y]=q.top();
		q.pop();
		int z=x+y;
		while(z%k==0)z/=k,--t1;
		cout<<x<<' '<<y<<'\n';
		q.emplace(t1,z);
	}
	return 0;
}