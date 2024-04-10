#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m,p;
int dp[100001],a[100001];
vector<int>v[100001];
int sp[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	for(int i=0; i<n*m ;i++){
		cin >> a[i];
		v[a[i]].push_back(i);
		dp[i]=1e9;
		if(a[i]==1){
			dp[i]=i/m+i%m;
		}
	}
	
	for(int i=2; i<=p ;i++){
		if(v[i-1].size()*v[i].size()<n*m){
			for(auto cur:v[i-1]){
				for(auto nx:v[i]){
					dp[nx]=min(dp[nx],dp[cur]+abs(cur/m-nx/m)+abs(cur%m-nx%m));
				}
			}
			continue;
		}
		for(int j=0; j<n*m ;j++){
			sp[j]=1e9;
		}
		for(auto cur:v[i-1]){
			sp[cur]=dp[cur];
		}
		for(int j=0; j<n*m ;j++){
			if(j%m) sp[j]=(sp[j]<=sp[j-1]?sp[j]:sp[j-1]+1);
		}
		for(int j=n*m-1; j>=0 ;j--){
			if(j%m) sp[j-1]=(sp[j-1]<=sp[j]?sp[j-1]:sp[j]+1);
		}
		int t=(n-1)*m;
		for(int j=0; j<t ;j++){
			sp[j+m]=(sp[j+m]<=sp[j]?sp[j+m]:sp[j]+1);
		}
		
		for(int j=t-1; j>=0 ;j--){
			sp[j]=(sp[j]<=sp[j+m]?sp[j]:sp[j+m]+1);
		}
		for(auto cur:v[i]){
			dp[cur]=sp[cur];
		}
	}
	cout << dp[v[p][0]] << '\n';
}