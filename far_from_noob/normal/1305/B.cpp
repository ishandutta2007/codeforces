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
    	string s;
    	cin>>s;
    	ll l=s.size();
    	vector<ll>v1,v2;
    	ll c1=0,c2=0;
    	fo(i,l){
    		if(s[i]=='(')v1.pb(i+1);
    		else v2.pb(i+1);
    	}
    	//cout<<v1.size()<<v2.size();
    	ll maxi=0,index;
    	fo(i,l){
    		if(s[i]=='(')c1++;
    		else c2++;
    		//cout<<c1<<c2<<endl;
    		if(maxi< min(c1, v2.size() -c2)){
    			maxi=min(c1,v2.size()-c2);
    			index=i;
    		}
    		//cout<<maxi;
    	}
    	if(maxi==0){cout<<0;return 0;}
    	else{
    		cout<<1<<endl;
    		cout<<2*maxi<<endl;
    		fo(i,maxi){
    			cout<<v1[i]<<" ";
    		}
    		ll l1=v2.size();
    		for(int i=l1-maxi; i<l1 ;i++){
    			cout<<v2[i]<<" ";
    		}

    	}
    	
    }

    return 0;
}