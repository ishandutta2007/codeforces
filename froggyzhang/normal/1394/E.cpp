#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int Q,n,a[N];
unordered_map<int,int> dp[N],vis[N];
vector<int> L[N],R[N];
int dfs(int l,int r){
	if(dp[r].count(l))return dp[r][l];
	int &ans=dp[r][l];
	for(auto x:R[r]){
		if(r-2*x+1>=l)ans=max(ans,dfs(l,r-x)+1);
		else break;
	}
	for(auto x:L[l]){
		if(l+2*x-1<=r)ans=max(ans,dfs(l+x,r)+1);
		else break;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	while(Q--){
		static int Z;
		++n;cin>>a[n];
		if(a[n]==a[n-1]){
			R[n].push_back(1);
			vis[n][1]=1;
		}
		for(auto x:R[n-1]){
			if(a[n]==a[n-2*x-1]){
				R[n].push_back(x+1);
			}
		}
		for(auto x:R[n]){
			L[n-2*x+1].push_back(x);
			vis[n][x]=1;
		}
		int p=0;
		for(auto x:R[n]){
			if(vis[n-x][x]){
				p=x;break;
			}
		}
		if(p){
			++Z;
			for(int i=1;i<=2*p;++i){
				for(auto x:R[n]){
					L[n-2*x+1].pop_back();
				}
				R[n].clear(),L[n].clear(),dp[n].clear(),vis[n].clear();
				--n;
			}
		}
		cout<<2*Z+dfs(1,n)<<' ';
	}
	cout<<'\n';
	return 0;
}