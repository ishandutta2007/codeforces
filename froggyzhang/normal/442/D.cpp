#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,dp[N],mx[N],se[N],f[N];
vector<int> G[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n+1;++i){
		cin>>f[i];
		for(int u=i;u^1;u=f[u]){
			int z=max(mx[u],se[u]+1);
			if(z==dp[u])break;
			dp[u]=z;
			if(z>mx[f[u]])se[f[u]]=mx[f[u]],mx[f[u]]=z;
			else se[f[u]]=max(se[f[u]],z);
		}
		cout<<mx[1]<<' ';
	}
	cout<<endl;
	return 0;
}