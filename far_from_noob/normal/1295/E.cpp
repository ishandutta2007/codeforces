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
const int n1=200005;

ll p[n1],a[n1];
ll tree1[3*n1];
ll presum[n1];

void update1(ll mini ,ll maxi, ll treeindex , ll index, ll val){
    if(mini==maxi){tree1[treeindex] = val; return ;}
    ll mid=(mini+maxi)/2;
    if(mid>=index){update1(mini, mid , 2*treeindex , index , val); }
    else update1(mid+1 , maxi , 2*treeindex+1 , index , val);
    tree1[treeindex]= tree1[treeindex*2] + tree1[2*treeindex +1];
}
ll sumval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 0;
    if(l==mini && r== maxi){return tree1[index];  }
    ll mid= (mini+maxi)/2;
    return  sumval(mini, mid , l ,min(r,mid) , 2*index)+ sumval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) ;
}

ll val[n1];
ll tree[3*n1], lazy[3*n1];

void push(ll index){
    tree[2*index]+=lazy[index];
    lazy[2*index]+=lazy[index];
    tree[2*index+1]+=lazy[index];
    lazy[2*index+1]+=lazy[index];
    lazy[index]=0;
}

void update(ll mini ,ll maxi, ll treeindex , ll l, ll r, ll val){
    if(l>r)return ;
    if(mini==l && maxi ==r){tree[treeindex]+= val;  lazy[treeindex] += val; return ;}
    ll mid=(mini+maxi)/2;
    update(mini, mid , 2*treeindex , l, min(r,mid) , val); 
    update(mid+1 , maxi , 2*treeindex+1 , max(mid+1, l), r , val);
    tree[treeindex]= min(tree[treeindex*2] , tree[2*treeindex +1]);
}

ll minval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 1e15;
    if(l==mini && r== maxi){return tree[index];  }
    ll mid= (mini+maxi)/2;
    push(index);
    return min( minval(mini, mid , l ,min(r,mid) , 2*index) , minval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) );
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
        cin>>n;
        fo(i,n)cin>>p[i];
        fo(i,n)cin>>a[p[i]-1];
        presum[0]=a[0];
        fo1(i,n-1)presum[i]=presum[i-1]+a[i];
        fo(i,3*n1)tree1[i]=0;
        if(p[0]==1){cout<<0 ; return 0;}
        ll ans=a[p[0]-1];
        //cout<<ans;
        fo(i,3*n1)tree[i]=1e15,lazy[i]=0;
        fo(i,n-1){
            ll node=p[i];
            update1(0,n-1, 1, node-1, a[node-1]);
            ll a1= sumval(0,n-1, 0,node-1, 1) ,a2=sumval(0,n-1,node,n-1, 1); 
            //cout<<a1<<" "<<a2<<endl;
            ll sum=presum[node-1]- a1 + a2;
            //cout<<sum<<endl;
            ll  temp= minval(0,n-1, node-1,node-1 , 1);
            //cout<<temp<<endl;
            update(0,n-1,1, 0,node-2,a[node-1]);
            update(0,n-1, 1, node,n-1,-a[node-1]);
            update(0,n-1,1, node-1,node-1, -temp + sum);
            
            if(i==n-1)ans=min(ans , minval(0,n-1, 0, n-2, 1) );
            else ans=min(ans , minval(0,n-1, 0, n-1, 1) );
            //cout<<ans;


        }
        cout<<ans;
        








        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}