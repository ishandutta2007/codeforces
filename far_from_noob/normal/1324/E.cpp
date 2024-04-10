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
ll ans[2001][2000];
ll a[2000];
void findans(ll i, ll h1, ll l ,ll r, ll h,ll n){
    if(i==0){
        if(h1>=l && h1<=r)ans[0][h1]=1;
        else ans[0][h1]=0;
        return ;
    }
    if(ans[i-1][(h1+a[n-i])%h]==-1)findans(i-1, (h1+a[n-i])%h , l , r, h, n);
    if(ans[i-1][(h1+a[n-i]-1)%h]==-1)findans(i-1, (h1+a[n-i]-1)%h , l , r, h, n);
    ans[i][h1]=max(ans[i-1][(h1+a[n-i])%h], ans[i-1][(h1+a[n-i]-1)%h]);
    if(i!=n)if(h1>=l && h1<=r)ans[i][h1]++;

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
        ll h,l , r;
        cin>>n>>h>>l>>r;
        fo(i,n)cin>>a[i];
        fo(i,n+1)fo(j,h)ans[i][j]=-1;
        findans(n,0 , l , r, h, n);
        cout<<ans[n][0];

        
    }

    return 0;
}