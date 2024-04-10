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
        cin>>n;
        ll p[n+1];
        fo(i,n)cin>>p[i+1];
        ll c[n+1];
        fo(i,n)cin>>c[i+1];
        ll temp[n+1];
        fo(i,n)temp[i+1]=0;
        vector<vector<ll> >vects;
        fo1(i,n){
            if(temp[i]==1)continue;
            vector<ll>v;
            ll node=i;
            v.pb(i);
            temp[i]=1;
            while(p[node]!=i){
                node=p[node];
                v.pb(node);
                temp[node]=1;
            }
            vects.pb(v);
        }
        ll ans=n;
        fo(i,vects.size()){
            vector<ll>v=vects[i];
            ll l=v.size();
            vector<ll>factors;
            for(int j=1; j*j<=l ;j++){
                if(l%j==0){factors.pb(j);
                if(l/j != j ) factors.pb(l/j);
                }
            }
            //cout<<l;
            sort(all(factors));
            ans=min(ans,l);
            //fo(i,l)cout<<v[i];
            fo(j,factors.size()){
                //cout<<factors[j]<<" ";
                for( int k=0;k<(l/factors[j]); k++){
                    flag=0;
                    for(int p=k;p<l;p+=(l/factors[j])){
                        if(p>=(l/factors[j])){
                            if(c[v[p]]!=c[v[p- (l/factors[j]) ]])flag=1;
                        }
                    }
                    if(flag==0)ans=min(ans,(l/factors[j]) );
                }
                //cout<<ans<<l<<" ";
            }
        }
        cout<<ans<<endl;
        
    }
 
    return 0;
}