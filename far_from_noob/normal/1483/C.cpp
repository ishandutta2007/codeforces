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

ll tree2[1200005];


void update2(ll mini ,ll maxi, ll treeindex , ll index, ll val){
    if(mini==maxi){tree2[treeindex] = val; return ;}
    ll mid=(mini+maxi)/2;
    if(mid>=index){update2(mini, mid , 2*treeindex , index , val); }
    else update2(mid+1 , maxi , 2*treeindex+1 , index , val);
    tree2[treeindex]= max(tree2[treeindex*2] , tree2[2*treeindex +1]);
}

ll maxval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return -1e16;
    if(l==mini && r== maxi){return tree2[index];  }
    ll mid= (mini+maxi)/2;
    return max( maxval(mini, mid , l ,min(r,mid) , 2*index) , maxval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) );
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
        fo(i,1200005){ tree2[i]=-1e16;}
        cin>>n;
        ll h[n],b[n];
        fo(i,n)cin>>h[i];
        fo(i,n)cin>>b[i];
        map<ll,ll>m1;
        fo(i,n)m1[h[i]]=i;
        stack<ll>s;
        fo(i,n){
            if(i==0){
                ll ans =b[i];
                //update1(0,n,1,0,0);
                //update1(0,n , 1,h[i],ans);
                update2(0,n, 1, 0, ans);
                s.push(h[i]);
            }
            else{
                while(s.size()>0 ){
                    ll node =s.top();
                    //cout<<node<<endl;
                    if(node < h[i])break;
                    else s.pop();
                }
               
                //cout<<s.size()<<endl;
                ll ind;
                ll flag=0;
                if(s.size()>0)ind = m1[s.top()];
                else {ind =0 ; flag=1;}
                ll val=-1e16;
                ll f=0;
                if(s.size()>0){
                    val = maxval(0,n,ind, ind,1);
                }
                
                //cout<<ind<<endl<<endl;
                s.push(h[i]);
                //cout<<s.size()<<endl;
                //cout<< maxval(0,n,i-1 , i-1, 1)<<endl;

                ll ans = max  (val , maxval(0,n,ind , i-1, 1) + b[i] );
                if(flag )ans =max(ans, b[i]);
                if(f)ans=min(ans,b[i]);
                //ans= max(ans , maxval(0,n, i) + b[i])
                //cout<<ans<<endl;

                //update1(0,n , 1,h[i],ans);
                update2(0,n, 1, i, ans);
                //cout<< maxval(0,n,i , i, 1)<<endl;
            }
        }
        //cout<<endl;
        cout<<maxval(0,n,n-1,n-1,1 );






        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}