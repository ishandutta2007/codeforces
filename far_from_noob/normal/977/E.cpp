#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
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
    vector<ll>prime; map<ll ,ll>ifused;
    for(ll i=2;i<1000000;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=1000000)ifused[j]=1,j+=i;
    }
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        vector<ll>v[n+1];
        map<ll,ll>m1;
        fo(i,m){
            ll a ,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll ans=0;
        fo1(i,n){
            if(m1[i]==0){
                m1[i]==1;
                flag=0;
                if(v[i].size()==2)if(m1[v[i][0]] ==0 && m1[v[i][1]]==0){
                    ll b=v[i][0];
                    ll a=i;
                    while(b!=i){
                        //cout<<b;
                        if(m1[b]==1){flag=1;break;}
                        m1[b]=1;
                        if(v[b].size()==2){
                            if(v[b][0]==a)a=b,b=v[b][1];
                            else a=b,b=v[b][0];
                        }
                        else{flag=1;break;}
                    }
                    if(flag==0)ans++;
                }
                //if(flag==0)ans++;
            }
        }
        cout<<ans;
    }

    return 0;
}