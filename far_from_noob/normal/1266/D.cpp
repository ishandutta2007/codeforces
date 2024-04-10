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
        cin>>n>>m;
        ll a[n+1];
        fo1(i,n)a[i]=0;
        fo(j,m){
            ll b,c,d;
            cin>>b>>c>>d;
            a[b]-=d;
            a[c]+=d;
        }
        vector<pair<ll,ll> >v;
        fo1(i,n){
            v.pb(mp(a[i],i));
        }
        sort(all(v));
        vector<pair<pair<ll,ll> ,ll > >ans;
        ll temp1=0;
        ll temp2=v.size()-1;
        while(v[temp1].fi!=0 && temp1<temp2){
            if(-1*v[temp1].fi>v[temp2].fi){
                ans.pb(mp(mp(v[temp1].se,v[temp2].se), v[temp2].fi));
                v[temp1].fi+=v[temp2].fi;
                temp2--;
            }
            else if(-1*v[temp1].fi<v[temp2].fi){
                ans.pb(mp(mp(v[temp1].se,v[temp2].se), -1*v[temp1].fi));
                v[temp2].fi+=v[temp1].fi;
                temp1++;
            }
            else{
                ans.pb(mp(mp(v[temp1].se,v[temp2].se), -1*v[temp1].fi));
                temp1++;
                temp2--;
            }
        }
        cout<<ans.size()<<endl;
        fo(i,ans.size()){
            cout<<ans[i].fi.fi<<" "<<ans[i].fi.se<<" "<<ans[i].se<<endl;
        }
    }

    return 0;
}