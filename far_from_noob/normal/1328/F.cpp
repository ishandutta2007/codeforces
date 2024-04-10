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
        cin>>n>>k;
        ll a[n];
        map<ll,ll>m1,m2;
        fo(i,n)cin>>a[i],m1[a[i]]++;
        vector<pair<ll,ll> >v;
        sort(a,a+n);
        fo(i,n){
            if(m2[a[i]]==0){
                if(m1[a[i]]>=k){cout<<0; return 0;}
                v.pb(mp(a[i], m1[a[i]]));
                m2[a[i]]=1;
            }
        }
        vector<pair<ll,ll> >v1;
        ll ans=1e18;
        fo(i,v.size()){
            if(i==0)v1.pb(mp(0,v[0].se));
            else{
                ll cc=v1[i-1].se+v[i].se;
                ll sum=(v[i].fi-v[i-1].fi)*v1[i-1].se + v1[i-1].fi;
                v1.pb(mp(sum,cc));
                if(cc>=k)ans=min(ans, sum - (cc- k));
                //cout<<sum<<" "<<cc<<endl;
            }
        }
        //cout<<ans<<endl;
        vector<pair<ll,ll> >v2;
        fo(i,v.size()){
            v2.pb(v[v.size()-1-i]);
        }
        vector<pair<ll,ll> >v3;
        fo(i,v.size()){
            if(i==0)v3.pb(mp(0,v2[0].se));
            else{
                ll cc=v3[i-1].se+v2[i].se;
                ll sum=(v2[i-1].fi-v2[i].fi)*v3[i-1].se + v3[i-1].fi;
                v3.pb(mp(sum,cc));
                if(cc>=k)ans=min(ans, sum - (cc- k));
                //cout<<cc<<sum<<endl;
            }
        }
        //cout<<ans<<endl;
        fo(i,v.size()){
            ans= min (v1[i].fi + v3[v.size()-1-i].fi - n+k , ans);
        }
        cout<<ans;






        
    }

    return 0;
}