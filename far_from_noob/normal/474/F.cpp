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
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
const int N=100005;
ll a[N];
pair<ll,ll> tree[3*N];

void build(ll low, ll high, ll index){
    if(low==high){
        tree[index]=mp(a[low],1);
        return;
    }
    ll mid=(low+high)/2;
    build(low,mid,2*index);
    build(mid+1 ,high, 2*index+1);
    if(tree[2*index].fi ==tree[2*index+1].fi){
        tree[index]=mp(tree[2*index].fi  ,tree[2*index].se +tree[2*index+1].se );
    }
    else{
        if(tree[2*index].fi % tree[2*index +1 ].fi == 0)tree[index]=mp(tree[2*index+1].fi  ,tree[2*index+1].se );
        else if(tree[2*index+1].fi % tree[2*index].fi == 0)tree[index]=mp(tree[2*index].fi  ,tree[2*index].se );
        else tree[index]=mp(gcd(tree[2*index].fi , tree[2*index+1].fi) , 0);
    }
}

pair<ll,ll> query(ll low,ll high , ll l , ll r, ll index ){
    if(l>r)return mp(1,1);
    if(l==low && r==high)return tree[index];
    ll mid=(low+high)/2;

    pair<ll,ll>p1=query(low, mid, l ,min(r,mid) , 2*index);
    pair<ll,ll>p2=query(mid+1,high, max(l,mid+1) , r, 2*index+1);
    if(l>min(r,mid))return p2;
    else if(max(l,mid+1)>r)return p1;
    else{
        if(p1.fi==p2.fi)return(mp(p1.fi , p1.se+p2.se));
        else if(p1.fi%p2.fi==0)return p2;
        else if(p2.fi%p1.fi==0)return p1;
        else return mp(gcd(p1.fi,p2.fi) , 0);
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
        fo(i,n){
            cin>>a[i];
        }
        build(0,n-1,1);
        cin>>q;
        fo(i,q){
            ll l,r;
            cin>>l>>r;
            cout<< r+1-l-query(0,n-1, l-1, r-1 , 1).se<<endl;
        }
        
        
    }

    return 0;
}