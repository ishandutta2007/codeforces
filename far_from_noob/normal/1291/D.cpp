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
    	ll a[l];
    	ll count[l][26];
    	fo(i,26){if(i==s[0]-'a')count[0][i]=1;else count[0][i]=0;}
    	fo(i,l){
    		if(i==0){a[i]=1;continue;}
    		else if(s[i]==s[i-1])a[i]=a[i-1];
    		else a[i]=a[i-1]+1;
    		fo(j,26){if(j==s[i]-'a')count[i][j]=count[i-1][j]+1;else count[i][j]=count[i-1][j];}
    	}
    	cin>>q;
    	fo(i,q){
    		ll a1,b;
    		cin>>a1>>b;
    		if(a[b-1]==a[a1-1] && b-a1>0)cout<<"No"<<endl;
    		else {
    			if(s[b-1]==s[a1-1]){
    				ll temp=0;
    				fo(i,26){
    					if(a1>1){if(count[b-1][i]-count[a1-2][i]==0)temp++;}
    					else {if(count[b-1][i]==0)temp++;}
    				}
    				//cout<<temp;
    				if(temp==24)cout<<"No"<<endl;
    				else cout<<"Yes"<<endl;
    			}
    			else cout<<"Yes"<<endl;
    		}
    		//cout<<endl;
    	}
    	
    }

    return 0;
}