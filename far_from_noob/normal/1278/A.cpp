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
    	string s1,s2;
    	cin>>s1>>s2;
    	map<ll,ll>m1;
    	fo(i,s1.size())m1[s1[i]-'a']++;
    	flag=0;
    	ll l=s2.size();
    	if(s1.size()>l){cout<<"NO"<<endl ; continue;}
    	for(int i=0;i<l+1-s1.size();i++){
    		map<ll,ll>m2;
    		for(int j=i;j<i+s1.size();j++){
    			m2[s2[j]-'a']++;
    		}
    		ll temp=0;
    		fo(i,s1.size()){
    			if(m1[s1[i]-'a']==m2[s1[i]-'a']);
    			else {temp=1; break;}
    		}
    		if(temp==0)flag=1;
    	}
    	if(flag==0)cout<<"NO"<<endl;
    	else cout<<"YES"<<endl;
    	
    }

    return 0;
}