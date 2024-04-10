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
    	cin>>n;
    	ll a[n];
    	fo(i,n)cin>>a[i];
    	ll ans=0;
    	for(int l=25;l>=0;l--){
    		ll cc=0;
    		vector<ll>v;
    		fo(i,n){if(a[i]>=(ll)pow(2,l+1))a[i]-=(ll)pow(2,l+1); if(a[i]>=(ll)pow(2,l))v.pb(a[i]-(ll)pow(2,l)); } 
    		sort(a,a+n);
    		sort(all(v));
    		ll count=0;
    		ll temp=0;
    		ll temp1=0;
    		for(int i=n-1;i>=0;i--){
    			while(a[i]+a[temp] < (ll)pow(2,l) && temp< i){ temp++; }
    			while(a[i]+a[temp1]<  (ll)pow(2,l+1) && temp1< i ){temp1++; }
    			//if(l==3)cout<<temp<<temp1<<endl;
    			count+=min(i,temp1)-min(i,temp);

    		}
    		ll n1=v.size();
    		temp=0;
    		//ll temp1=0;
    		//if(l==2)cout<<count<<" ";
    		for(int i=n1-1;i>=0;i--){
    			while(v[i]+v[temp] < (ll)pow(2,l) && temp< i){ temp++; }
    			//while(a[i]+a[temp1]<  (ll)pow(2,l+1) && temp1< i ){temp1++; }
    			//if(l==3)cout<<temp<<temp1<<endl;
    			count+=i-min(i,temp);

    		}
    		//if(l==2)cout<<count<<" ";
    		if(count%2==1)ans+=(ll)pow(2,l);
    	}
    	cout<<ans;







    	// map<ll,ll>m1;
    	// fo(i,n){
    	// 	ll temp=a[i];
    	// 	for(int j=30;j>=0;j--){
    	// 		if(temp>=(ll)pow(2,j)){
    	// 			temp-=(ll)pow(2,j);
    	// 			m1[j]++;
    	// 		}
    	// 	}

    	// }
    	// ll ans=0;
    	// ll temp=0;
    	// //cout<<m1[1]<<m1[0];
    	// fo(i,30){
    	// 	if(i==0){
    	// 		if((m1[0]*(n-m1[0]))%2==1)ans+=1;
    	// 	}
    	// 	else{
    	// 		if(( m1[i]*(n-m1[i])  +  (m1[i-1]*(m1[i-1]-1)) / 2 )%2==1)ans+=(ll)pow(2,i);
    	// 	}
    	// }
    	// cout<<ans;

    	
    }

    return 0;
}