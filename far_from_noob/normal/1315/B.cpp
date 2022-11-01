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
        ll a,b,p;
        //cin>>n;
        cin>>a>>b>>p;
        string s;
        cin>>s;
        n=s.size();
        ll ans=n;
        ll temp=0;
        for(int i=n-2;i>=0;i--){
            if(i==n-2){
                if(s[i]=='A')temp+=a;
                else temp+=b;
            }
            else if(s[i]==s[i+1] );
            else if(s[i]=='B')temp+=b;
            else temp+=a;
            //cout<<temp;
            if(temp<=p)ans=i+1;
        }
        cout<<ans<<endl;
        
    }

    return 0;
}