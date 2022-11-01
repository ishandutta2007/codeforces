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
ll mod1=1000000007,mod;
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
vector<ll> multiply(vector <ll >v1 , vector<ll > v2 , ll k, ll x){
    vector<ll>v(x);
    fo(i,x)v[i]=0;
    fo(i,x){
        v[(i*(po(10,k,1,1,10)))%mod]+=v1[i];
        v[(i*(po(10,k,1,1,10)))%mod]%=mod1;
    }
    vector<ll >ans(x);
    fo(i,x){
        ans[i]=0;
        fo(j,x){
            ans[i]+=(v[j]* v2[(x+i-j)%mod])%mod1;
            ans[i]%=mod1;
        }
    }
    return ans;

}
vector<ll> block;

vector<ll> findans(ll b){
    if(b==1)return block;

    vector<ll> v= findans(b/2);
    if(b%2==0) return multiply(v,v, b/2 , mod);

    vector<ll>v1= multiply(v,block, 1,mod);
    return multiply(v1,v, b/2 , mod);
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
        ll b,k1,x;
        cin>>n>>b>>k1>>x;
        mod=x;
        block.clear();
        fo(i,x)block.pb(0);
        fo(i,n){
            ll a;
            cin>>a;
            block[a%x]++;
        }
        //cout<<block[0]<<block[1];
        vector<ll>vans;
        vans=findans(b);
        //'fo(i,x)cout<<vans[i]<<" ";
        cout<<vans[k1];
        
    }

    return 0;
}