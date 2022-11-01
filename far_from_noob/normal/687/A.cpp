#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define mp make_pair
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
vector<ll>v[100005];
ll value[100005];
void fun(ll setv,ll a){
    value[a]=setv;
    fo(i,v[a].size()){
        if(value[v[a][i]]==0){
            if(setv==1)fun(2,v[a][i]);
            else fun(1,v[a][i]);
        }
        else if(value[a]==value[v[a][i]]){
            value[0]=-1;
            return ;
        }
    }
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
        cin>>m;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        //ll value[n];
        fo(i,n+1)value[i]=0;
        fo(i,n){
            if(value[i+1]==0){
                fun(1,i+1);
            }
            if(value[0]==-1){
                cout<<-1;
                return 0;
            }
        }
        ll count=0;
        fo(i,n)if(value[i+1]==1)count++;
        cout<<count<<endl;
        fo(i,n)if(value[i+1]==1)cout<<i+1<<" ";
        cout<<endl;
        cout<<n-count<<endl;
        fo(i,n)if(value[i+1]==2)cout<<i+1<<" ";
    
        
    }

    return 0;
}