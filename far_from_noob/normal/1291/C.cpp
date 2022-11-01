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
    	cin>>n>>m>>k;
    	ll a[n];
    	fo(i,n)cin>>a[i];
    	ll maxi[m];
    	fo(i,m){
    		maxi[i]=max(a[i],a[n-1-(m-1)+i]);
    	}
    	//fo(i,m)cout<<maxi[i];
    	if(k>=m-1)k=m-1;
    	ll ans=0;
    	multiset<ll>s;
    	multiset<ll>::iterator it;
    	ll k2=m-k;
    	fo(i,k2)s.insert(maxi[i]);
    	//cout<<endl;
    	ll temp=0;
    	//ll ans=0;
    	while(temp<=k){
    		//cout<<s.size();
    		it=s.begin();
    		ll kk=*it;
    		//cout<<kk;
    		ans=max(ans,kk);
    		it=s.lower_bound(maxi[temp]);
    		s.erase(it);
    		//it=s.begin(); cout<<*it<<endl;
    		s.insert(maxi[(temp+k2)%m]);
    		temp++;

    	}
    	cout<<ans<<endl;
    	
    }

    return 0;
}