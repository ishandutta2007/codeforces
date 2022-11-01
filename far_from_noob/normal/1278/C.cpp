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
    cin>>t;
    //t=1;
    while(t--){
    	cin>>n;
    	ll a[2*n];
    	fo(i,2*n)cin>>a[i];
    	map<ll,ll>m1;
    	ll s=0,b=0;
    	fo(i,n){
    		if(a[i]==1)s++;
    		else b++;
    		m1[s-b]=i+1;
    	}
    	ll s1=0,b1=0;
    	ll ans=m1[0];
    	for(int i=2*n-1;i>=n;i--){
    		ll kk=2*n -i;
    		if(a[i]==1)s1++;
    		else b1++;
    		
    		if(m1[b1-s1]>0 || b1-s1==0)ans=max(ans, kk + m1[b1-s1]);
    		
    	}
    	cout<<2*n-ans<<endl;
    	
    }

    return 0;
}