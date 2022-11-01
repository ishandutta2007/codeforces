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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        cin>>k;
        ll a[n];
        fo(i,n)cin>>a[i];
        sort(a,a+n);
        map<ll,ll>m1;
        vector<ll>v;
        fo(i,n){
            if(m1[a[i]]==0)v.pb(a[i]);
            m1[a[i]]++;
        }
        ll l=0;
        ll r=v.size()-1;
        while(v[l]!=v[r]){
            if(m1[v[l]]  <= m1[v[r]]  ){
                if(k >= m1[v[l]] * (v[l+1]-v[l] )){
                    m1[v[l+1]]+=m1[v[l]];
                    k=k-m1[v[l]] * (v[l+1]-v[l] );
                    l++;
                }
                else{
                    cout<<v[r] -(v[l]+ k/ m1[v[l]]);
                    return 0;
                }
                
            }
            else {
                 if(k >= m1[v[r]] * (v[r]-v[r-1] )){
                    m1[v[r-1]]+=m1[v[r]];
                    k=k-m1[v[r]] * (v[r]-v[r-1] );
                    r--;
                }
                else{
                    cout<<(v[r]- k/m1[v[r]] )-v[l];
                    return 0;
                }
            }
        }
        cout<<0;
        
        
    
    }

    return 0;
}