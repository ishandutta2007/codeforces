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
ll mini(ll a,ll b){if(a>b)return b;else return a;}
ll maxi(ll a,ll b){if(a>b)return a;else return b;}
vector<ll>v[300005];
vector<pair<ll,ll> >queries[300005];
ll temp[300005];
ll tree[900000];
ll ans[300005];

void update(ll min, ll max ,ll treeindex, ll index , ll val){
    if(min==max){tree[treeindex]+=val; return ;}
    ll mid=(min+max)/2;
    if(mid>=index){
        update(min,mid , 2*treeindex , index, val);
        tree[treeindex]+=val;
    }
    else{
        update(mid+1, max , 2*treeindex + 1 ,index, val);
        tree[treeindex]+=val;
    }
    return;
}

ll calans(ll min , ll max ,ll treeindex, ll l , ll r ){
    if(l>r)return 0;
    if(l==min && r==max)return tree[treeindex];
    ll mid=(min +max)/2;
    ll myans= calans( min , mid , 2*treeindex , l , mini(r,mid) )+ calans(mid+1, max, 2*treeindex+1, maxi(mid+1,l), r);
    return myans;
}

void findans(ll node, ll root, ll n, ll height){
    fo(i,queries[node].size()){
        if(queries[node][i].fi + height>=n){
            temp[n]+=queries[node][i].se;
            update(0, n, 1, n, queries[node][i].se);
        }
        else {
            temp[queries[node][i].fi + height]+=queries[node][i].se;
            update(0, n, 1, queries[node][i].fi + height, queries[node][i].se);
        }
    }

    ans[node] = calans(0,n,1, height  , n );
     // cout<<node<< " "<<ans[node]<<endl;
     // fo(i,n+1)cout<<temp[i]<<" ";cout<<endl;
     // fo(i,3*n)cout<<tree[i+1]<<" ";cout<<endl;

    fo(i,v[node].size()){
        if(v[node][i]!=root)findans( v[node][i],node, n ,height+1);
    }

    fo(i,queries[node].size()){
        if(queries[node][i].fi + height>=n){
            temp[n]-=queries[node][i].se;
            update(0, n, 1, n, -queries[node][i].se);
        }
        else {
            temp[queries[node][i].fi + height]-=queries[node][i].se;
            update(0, n, 1, queries[node][i].fi + height, -queries[node][i].se);
        }
    }

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
        cin>>q;
        fo(i,q){
            ll a,b,c;
            cin>>a>>b>>c;
            queries[a].pb(mp(b,c));
        }
        fo(i,n+1)temp[i]=0;
        fo(i,900000)tree[i]=0;
        findans(1,1,n,0);
        fo(i,n)cout<<ans[i+1]<<" ";

    }

    return 0;
}