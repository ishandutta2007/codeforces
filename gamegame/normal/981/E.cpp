#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll m1=1e9+7,m2=1e9+9;
int n,q;
ll dp[10001];
ll dp2[10001];
bool ok[10001];
vector<int>a[10001],b[10001];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i=1; i<=q ;i++){
    	int l,r,x;
    	cin >> l >> r >> x;
    	a[l].push_back(x);
    	b[r].push_back(x);
	}
	dp[0]=dp2[0]=1;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<a[i].size() ;j++){
			for(int k=n; k>=a[i][j] ;k--){
				dp[k]+=dp[k-a[i][j]];
				dp2[k]+=dp2[k-a[i][j]];
				if(dp[k]>=m1) dp[k]-=m1;
				if(dp2[k]>=m2) dp2[k]-=m2;
				ok[k]|=(dp[k]!=0);
			}
		}
		for(int j=0; j<b[i].size() ;j++){
			for(int k=b[i][j]; k<=n ;k++){
				dp[k]-=dp[k-b[i][j]];
				dp2[k]-=dp2[k-b[i][j]];
				if(dp[k]<0) dp[k]+=m1;
				if(dp2[k]<0) dp2[k]+=m2;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n ;i++) if(ok[i]) ans++;
	cout << ans << endl;
	for(int i=1; i<=n ;i++) if(ok[i]) cout << i << ' ';
}