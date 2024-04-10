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
        vector<ll>v[n+1];
        pair<ll,ll>p[n];
        fo(i,n-1){
            ll a,b;

            cin>>a>>b;
            p[i]=mp(a,b);
            v[a].pb(b);
            v[b].pb(a);
        }
        ll c1=0,c2=0;
        flag=0;
        vector<ll>ans;
        fo1(i,n){
            if(v[i].size()==1)ans.pb(i);
        }
        if(ans.size()==2){
            fo(i,n-1)cout<<i<<endl;
        }
        else{
            map<pair<ll,ll> , ll >m1;
            fo(i,ans.size()){
                m1[mp(ans[i],v[ans[i]][0])]=i+1;
                m1[mp(v[ans[i]][0],ans[i])]=i+1;
            }

            ll temp=ans.size();
            fo(i,n-1){
                if(m1[p[i]]!=0)cout<<m1[p[i]]-1;
                else{
                    cout<<temp;
                    temp++;
                }
                cout<<endl;
            }
        }

    }

    return 0;
}