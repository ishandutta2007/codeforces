#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
    	cin>>n>>m;
    	ll a[n][m],dp[n][m];
    	fo(i,n)fo(j,m){cin>>a[i][j],dp[i][j]=0;  if( j>0)a[i][j]+=a[i][j-1];} 
    	fo(i,m)dp[0][i]=a[0][i];
    	fo1(i,n-1){
    		if(i%2==1){
    			for(int j=m-2;j>=0;j--){
    				if(j==m-2)dp[i][j]=dp[i-1][j+1];
    				else dp[i][j]=max(dp[i][j+1],dp[i-1][j+1]);
    				//cout<<dp[i][j];
    			}
    			for(int j=m-2;j>=0;j--)dp[i][j]+=a[i][j];
    		}
    		else{
    			fo1(j,m-1){
    				if(j==1)dp[i][j]=dp[i-1][j-1];
    				else dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]) ;
    				//cout<<dp[i][j];
    			}
    			fo1(j,m-1)dp[i][j]+=a[i][j];
    		}
    	} 	
    	ll maxi=-1*mod;

    	if(n%2==1)fo1(i,m-1)maxi=max(maxi,dp[n-1][i]);
    	else fo(i,m-1)maxi=max(maxi,dp[n-1][i]);
    	cout<<maxi;
    }

    return 0;
}