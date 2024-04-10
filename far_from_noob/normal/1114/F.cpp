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
ll a[400005];

ll tree[1200005],lazy[1200005];

void build(ll mini , ll maxi , ll index){
    if(mini==maxi){tree[index]= a[mini]; return ;}
    ll mid=(mini+maxi)/2;
    build(mini, mid , 2*index);
    build(mid+1 ,maxi,2*index +1);
    tree[index]= tree[2*index ] * tree[2*index +1] %mod;
    return ;
}

void push(ll index,ll mini, ll maxi){
    ll mid=(mini+maxi)/2;
    tree[2*index]*=power(lazy[index] ,(mid+1-mini)); tree[2*index]%=mod;
    lazy[2*index]*=lazy[index];  lazy[2*index]%=mod;
    tree[2*index+1]*=power(lazy[index],(maxi-mid)); tree[2*index +1 ]%=mod;
    lazy[2*index+1]*=lazy[index];  lazy[2*index+1]%=mod;
    lazy[index]=1;
}

void update(ll mini ,ll maxi, ll treeindex , ll l ,ll r, ll val){
    if(mini==l && maxi==r){
        tree[treeindex] *= power(val,(maxi+1-mini)); tree[treeindex]%=mod;  
        lazy[treeindex]*=val; lazy[treeindex] %=mod;
         return ;}
    ll mid=(mini+maxi)/2;
    //cout<<mid<<" ";
    push(treeindex, mini, maxi);
    if(mid>=l){update(mini, mid , 2*treeindex , l, min(mid,r) , val); }
    if(mid+1<=r) update(mid+1 , maxi , 2*treeindex+1 , max(mid+1, l), r , val);
    tree[treeindex]= tree[treeindex*2] * tree[2*treeindex +1] %mod;
}

ll minval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 1;
    if(l==mini && r== maxi){return tree[index];  }
    push(index, mini, maxi);
    ll mid= (mini+maxi)/2;
    return  minval(mini, mid , l ,min(r,mid) , 2*index) * minval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) %mod ;
}

ll tree1[1200005],lazy1[1200005];
void push1(ll index,ll mini, ll maxi){
    ll mid=(mini+maxi)/2;
    tree1[2*index]|=lazy1[index];
    lazy1[2*index]|=lazy1[index];
    tree1[2*index+1]|=lazy1[index];
    lazy1[2*index+1]|=lazy1[index];
    lazy1[index]=0;
}

void update1(ll mini ,ll maxi, ll treeindex , ll l ,ll r, ll val){
    if(mini==l && maxi==r){tree1[treeindex] |= val; lazy1[treeindex]|=val; return ;}
    ll mid=(mini+maxi)/2;
    //cout<<mid<<" ";
    push1(treeindex, mini, maxi);
    if(mid>=l){update1(mini, mid , 2*treeindex , l, min(mid,r) , val); }
    if(mid+1<=r) update1(mid+1 , maxi , 2*treeindex+1 , max(mid+1, l), r , val);
    tree1[treeindex]= tree1[treeindex*2] | tree1[2*treeindex +1];
}

ll minval1(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 0;
    if(l==mini && r== maxi){return tree1[index];  }
    push1(index, mini, maxi);
    ll mid= (mini+maxi)/2;
    return  minval1(mini, mid , l ,min(r,mid) , 2*index) | minval1(mid+1 , maxi , max(l,mid+1), r, 2*index+1) ;
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
        ll prime[62]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

        //cout<<prime[61]<<endl;

        cin>>n>>q;
        fo(i,n)cin>>a[i];
        fo(i,1200005)lazy[i]=1, lazy1[i]=0,tree1[i]=0;
        build(0, n-1, 1);

        ll ans[62];
        fo(i,62)ans[i]= (prime[i]-1)*power(prime[i],mod-2)%mod;
        //cout<<2*ans[0]%mod;
        ll po[62];fo(i,62)po[i]=pow(2,i);

        fo(j,n){
            ll val = a[j];
            ll sum=0;
                fo(i,62){
                    if(val%prime[i]==0)sum+= po[i];
                }
                update1(0,n-1,1,j,j,sum);
        }

        fo(j,q){
            string s;
            cin>>s;
            if(s=="TOTIENT"){
                ll l,r;
                cin>>l>>r; l-- ; r--;
                ll ans1=0,ans2=0;
                ans1= minval(0,n-1,l,r,1 );
                ans2=minval1(0,n-1,l,r,1);

                //cout<<ans1<<" "<<ans2<<endl;
                fo(i,62){
                    if(ans2%2==1){ans1*=ans[i]%mod; ans1%=mod;}
                    ans2/=2;
                }
                cout<<ans1<<endl;
            }   
            else{
                ll l,r,val;
                cin>>l>>r>>val; l--; r--;
                update(0,n-1,1,  l , r,val );
                ll sum=0;
                fo(i,62){
                    if(val%prime[i]==0)sum+= po[i];
                }
                update1(0,n-1,1,l,r,sum);
            }
        }




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}