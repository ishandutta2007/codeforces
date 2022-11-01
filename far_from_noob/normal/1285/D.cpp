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
ll mat[100005][30];
ll power[30];
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll ans;
void findans(ll node, ll curr,vector<ll>v){
    vector<ll>temp1;
    vector<ll>temp2;
    fo(i,v.size()){
        if(mat[v[i]][node]==1)temp1.pb(v[i]);
        else temp2.pb(v[i]);
    }
    if(node==29){
        //cout<<"ccf";
        if(temp1.size()==0|| temp2.size()==0)ans=min(ans,curr);
        else ans=min(ans,curr+1);
        return ;
    }
    if(temp1.size()==0){
        findans(node+1,curr,temp2);
    }
    else if(temp2.size()==0){
        findans(node+1,curr,temp1);
    }
    else {
        findans(node+1,curr+(ll)power[29-node],temp1);
        findans(node+1,curr+(ll)power[29-node],temp2);
    }
    return ;
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
        ans=100000000000000;
        cin>>n;
        ll a[n];
        fo(i,n)cin>>a[i];
        vector<ll>v;
        fo(i,n)cin>>a[i],v.pb(i);
        //cout<<ans;
        
        fo(i,30)power[i]=(ll)pow(2,i);
        //cout<<(ll)pow(2,29);
        //ll mat[100005][30];
        fo(i,n){
            for(int j=29;j>=0;j--){
                if(a[i] >= (ll)power[j] ){
                    a[i]-=(ll)power[j];
                    mat[i][29-j]=1;
                }
                else mat[i][29-j]=0;
            }
        }
        findans(0,0,v);
        cout<<ans;



    }

    return 0;
}