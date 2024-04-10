#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
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
        cin>>n>>m;
        ll a[n][m],b[n][m];
        fo(i,n)fo(j,m){
            cin>>a[i][j];
            b[i][j]=0;
        }
        vector<ll>v1;vector<ll>v2;
        fo(i,n-1){
            fo(j,m-1){
                if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1 )
                {v1.pb(i+1);
                v2.pb(j+1);
                b[i][j] =1;
                b[i+1][j] =1;
                b[i][j+1] =1;
                b[i+1][j+1] =1;
                }
            }
        }
        fo(i,n){
            fo(j,m)if(a[i][j]!=b[i][j])flag=1;
        }
        if(flag)cout<<-1;
        else {
            cout<<v1.size()<<endl;
            fo(i,v1.size()){
                cout<<v1[i]<<" "<<v2[i]<<endl;
            }
        }
    }

    return 0;
}