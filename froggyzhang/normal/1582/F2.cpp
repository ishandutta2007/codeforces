#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const int inf=0x3f3f3f3f;
const int MX=1<<13;
int n,a[N],dp[MX];
vector<int> need[MX];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int j=0;j<MX;++j){
		dp[j]=MX-1;	
	}
	for(int j=0;j<MX;++j){
		need[j].push_back(0);	
	}
	dp[0]=-1;
	vector<int> ans;
	for(int i=1;i<=n;++i){
		for(auto j:need[a[i]]){
			if(dp[j]<a[i]&&dp[j^a[i]]>a[i]){
				for(int k=a[i]+1;k<=dp[j^a[i]];++k){
					need[k].push_back(j^a[i]);
				}
				dp[j^a[i]]=a[i];
			}
		}
		need[a[i]].clear();
	}
	for(int i=0;i<MX;++i){
		if(dp[i]<MX-1)ans.push_back(i);	
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}