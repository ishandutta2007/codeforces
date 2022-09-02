#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
int n,a[305];
map<int,int>cnt;
ll dp[305][305];
ll c[305][305];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i]; int b = a[i];
		for(int j=2;j*j<=a[i];j++){
			int cnt = 0;
			while(a[i]%j == 0){
				cnt++;
				a[i]/=j;
			}
			for(int k=0;k<cnt/2 * 2;k++) b/=j;
		}
		cnt[b]++; 
	}
	c[0][0] = 1;
	for(int i=1;i<305;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i) c[i][j] = 1;
			else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	vector<int>vec;
	for(map<int,int>::iterator it = cnt.begin();it != cnt.end();++it) vec.pb(it->sc);
	dp[0][vec[0]-1] = 1;
	for(int i=1;i<=vec[0];i++) dp[0][vec[0]-1] = (dp[0][vec[0]-1]*i%mod);
    int sum = vec[0]; 
	for(int i=1;i<vec.size();i++){
	    ll f = 1; for(int ii=1;ii<=vec[i];ii++) f = f*1LL*ii%mod;
		for(int ii=0;ii<=sum;ii++){
			for(int j=1;j<=vec[i];j++){
				for(int d=0;d<=j;d++){
					if(ii<d || sum-ii+1<j-d || dp[i-1][ii] == 0) continue;
					ll cur = dp[i-1][ii];
					cur *= c[vec[i]-1][j-1];
					cur %= mod;
					cur *= c[ii][d];
					cur %= mod;
					cur *= c[sum-ii+1][j-d];
					cur %= mod;
					cur *= f; cur %= mod;
					dp[i][ii-d+vec[i]-j] += cur;
					dp[i][ii-d+vec[i]-j] %= mod;
				}
			}
		} sum += vec[i]; 
	}
	cout << dp[vec.size()-1][0] << endl;
}