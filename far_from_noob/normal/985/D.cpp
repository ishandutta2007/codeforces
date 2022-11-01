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
void fun1(ll min,ll max, ll n){
    //cout<<min<<max<<endl;
    if(min==max){cout<<min ; return ;}
    ll mid=(min+max)/2 ;
    if((mid)*(mid+1)/2 < n){
        fun1(mid+1, max , n);
    }
    else fun1(min, mid , n);
 
}
void fun2(ll min,ll max, ll n, ll h){
    //cout<<min<<max<<endl;
    if(min==max){cout<<min ; return ;}
    ll mid=(min+max)/2 ;
    ll kk =mid-h;
    ll ans;
    if(kk%2==1){
        ans= (h)*(h+1)/2 + ((h+1) + (h+ kk/2) )*(kk/2)/2 +  (h + (h+ kk/2) )*(kk - kk/2)/2 ;
    }
    else{
        ans= (h)*(h+1)/2 +  ((h+1) + (h+ kk/2) )*(kk/2)/2 +  ((h+1) + (h+ kk/2) -2 )*(kk/2)/2; 
    }
    //cout<<ans<<endl;
    if(ans < n){
        fun2(mid+1, max , n , h);
    }
    else fun2(min, mid , n,  h);
 
}
 
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
        ll h;
        cin>>n>>h;
        //if(n>mod){cout<<"YES"; return 0;}
        if(h*(h+1)/2  >= n || h>1500000000)fun1(0, min(1500000000,h), n);
        else fun2(h,  2000000000,n , h );
        
    }
 
    return 0;
}