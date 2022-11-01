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
vector<ll>v[100005];
ll ansmax,odd,even;

void dfs(ll node, ll root, ll height){
    ll count=0;
    ll ans=0;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        else{
            if(v[v[node][i]].size()==1){ans=1; if(height%2==0)odd++; else even++;}
            else{
                count++;
                dfs(v[node][i],node,height+1);
            }
        }
    }
    ansmax+=count+ans;
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
        cin>>n;
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ansmax=0;
        odd=0,even=0;
        ll node;
        fo(i,n)if(v[i+1].size()>1)node=i+1;
        dfs(node,node,0);
        ll ansmin;
        if(even>0 && odd>0)ansmin=3;
        else ansmin=1;  
        cout<<ansmin<<" "<<ansmax<<endl;
        
    }

    return 0;
}