#include<bits/stdc++.h>
using namespace std;
#define N 18
typedef long long ll;
int n;;
double dp[1<<N],p[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>p[i][j];
		}
	}
	dp[1]=1;
	for(int i=2;i<1<<n;++i){
		for(int j=0;j<n;++j){
			if(i>>j&1){
				for(int k=j+1;k<n;++k){
					if(i>>k&1){
						dp[i]=max(dp[i^(1<<k)]*p[j][k]+dp[i^(1<<j)]*p[k][j],dp[i]);
					}
				}
			}
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
	return 0;
}