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
        ll ans[n];
        ll temp=0;
        ll main=1;
        fo(i,n){
            if(i==0)ans[i]=1;
            else {
                if(a[i]>a[i-1])ans[i]=ans[i-1]+1,main=max(main,ans[i]);
                else {
                    ans[i]=1;
 
                }
            }
        }
        //fo(i,n)cout<<ans[i];
        ll ans2[n];
        ans2[n-1]=ans[n-1];
        for(int i=n-2;i>=0;i--){
            if(ans[i]+1==ans[i+1])ans2[i]=ans2[i+1];
            else ans2[i]=ans[i];
        }
        //fo(i,n)cout<<ans2[i];
        for(int i=n-1;i>1;i--){
            if(ans[i]-ans[i-2]!=2 && a[i]>a[i-2])main=max(main,ans2[i]+ans2[i-2]-1);
        }
        cout<<main;
 
        
 
    }
 
    return 0;
}