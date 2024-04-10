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
    	string s,t;
    	cin>>s>>t;
    	ll ans=1;
    	ll l=s.size();
    	ll a[l][26];
    	ll index[26];
    	fo(i,26)index[i]=mod;
    	fo(i,26)a[l-1][i]=mod;
    	a[l-1][s[l-1]-'a']=l-1;
    	for(int i=l-2;i>=0;i--){
    		fo(j,26){
    			a[i][j]=a[i+1][j];
    		}
    		a[i][s[i]-'a']=i;
    	}
    	ll temp=0;
    	flag=0;
    	fo(i,t.size()){
    		if(a[0][t[i]-'a']==mod)flag=1;
    	}
    	if(flag==1){cout<<-1<<endl; continue;}
    	fo(i,t.size()){
    		if(temp>=l){temp=0;ans++;}
    		temp=a[temp][t[i]-'a'];
    		if(temp!=mod){
    			temp++;
    		}
    		else temp=0,ans++,i--;

    	}
    	cout<<ans<<endl;
    	
    }

    return 0;
}