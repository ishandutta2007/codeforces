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
#define vll vector<ll>
#define pll pair<ll,ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(a) -- no. of elements strictly less than a
// s.find_by_order(i) -- itertor to ith element (0 indexed)
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
ll tree[3000005],lazy[3000005];
ll a[1000005];

void build(ll mini , ll maxi , ll index){
    if(mini==maxi){tree[index]= a[mini]; return ;}
    ll mid=(mini+maxi)/2;
    build(mini, mid , 2*index);
    build(mid+1 ,maxi,2*index +1);
    tree[index]=max(tree[2*index ] , tree[2*index +1]);
    return ;
}

void push(ll index,ll mini, ll maxi){
    ll mid=(mini+maxi)/2;
    tree[2*index]+=lazy[index];
    lazy[2*index]+=lazy[index];
    tree[2*index+1]+=lazy[index];
    lazy[2*index+1]+=lazy[index];
    lazy[index]=0;
}

void update(ll mini ,ll maxi, ll treeindex , ll l ,ll r, ll val){
    if(mini==l && maxi==r){tree[treeindex] += val; lazy[treeindex]+=val; return ;}
    ll mid=(mini+maxi)/2;
    //cout<<mid<<" ";
    push(treeindex, mini, maxi);
    if(mid>=l){update(mini, mid , 2*treeindex , l, min(mid,r) , val); }
    if(mid+1<=r) update(mid+1 , maxi , 2*treeindex+1 , max(mid+1, l), r , val);
    tree[treeindex]= max(tree[treeindex*2] , tree[2*treeindex +1]);
}

ll maxval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 0;
    if(l==mini && r== maxi){return tree[index];  }
    push(index, mini, maxi);
    ll mid= (mini+maxi)/2;
    return  max(maxval(mini, mid , l ,min(r,mid) , 2*index) , maxval(mid+1 , maxi , max(l,mid+1), r, 2*index+1)) ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef NOOBxCODER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    #define NOOBxCODER 0
    #endif
    //cin>>t;
    t=1;
    while(t--){
        fo(i,1000002)a[i]=i;
        build(0,1000001,1);
        map<ll,pll>m1;

        cin>>q;
        fo(i,q){
            char c;
            cin>>c;
            if(c=='?'){
                ll T;cin>>T;
                cout<< maxval(0,1000001,0,T , 1) - maxval(0,1000001,T+1, T+1,1)+1 <<endl;
            }
            else if(c=='+'){
                ll T, d;
                cin>> T >> d;
                m1[i+1] = mp(T,d);
                update(0,1000001, 1, 0,T, d);
            }
            else{
                cin>>m;
                ll T = m1[m].fi, d = m1[m].se;
                update(0,1000001, 1, 0,T, -1*d);
            }
        }



        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}