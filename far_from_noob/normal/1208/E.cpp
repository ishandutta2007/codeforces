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
vector<ll>v[1000005];
vector<ll>tree[1000005];
 
void build(ll i , ll low, ll high  , ll index){
    if(low==high){
        tree[i][index]=v[i][low];
        return;
    }
    ll mid=(low+high)/2;
    build(i,low,mid,2*index);
    build(i, mid+1, high, 2*index+1);

    tree[i][index]=max(tree[i][2*index],tree[i][2*index+1]);
    return ;
}

ll findmax(ll i, ll low, ll high, ll l, ll r, ll index){
    if(l==low && r==high){
        return tree[i][index];
    }
    if(l>r)return -1000000000000;
    ll mid=(low+high)/2;
    return max( findmax(i,low, mid, l, min(r,mid) , 2*index ) , findmax(i , mid+1 , high , max(l ,mid+1) , r, 2*index+1) );

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
        ll w;
        cin>>n>>w;
        set<pair<ll,ll> >p;
        set<pair<ll,ll> > :: iterator it;
        fo(i,n){
            cin>>k;
            p.insert(mp(k,i));
            fo(j,k){
                cin>>q;
                v[i].pb(q);
            }
        }
        ll ans[n];
        //sort(all(p));
        fo(i,n){
            fo(j,3*v[i].size()+1)tree[i].pb(0);
        }
        fo(i,n){
            build( i, 0, v[i].size()-1 , 1);
        }
        fo(i,n)ans[i]=0;
        ll temp=0;
        ll sum=0;
        //cout<<findmax(1,0,0,0,0,1);
        fo(i,w){
            it = p.lower_bound(mp(min(i+1, w-i) , 0));
            while(it!=p.end()){
                pair<ll,ll>p1=*it;
                ll a=min(p1.fi , i+1);
                ll b =max(1, p1.fi+1 - (w-i));
                ll i1=p1.se;
                sum-=ans[i1];
                //cout<<sum;
                ans[i1]=findmax(i1, 0, p1.fi-1, b-1, a-1, 1);
                if(i+1> p1.fi || 1>p1.fi+1 - (w-i))ans[i1]=max(ans[i1],0);
                sum+=ans[i1];
                it++;
                //cout<<sum;
            }
            cout<<sum<<" ";
        }
        
        
    }

    return 0;
}