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
int tree[600005],lazy[600005];
//int tree2[600005]
int a[200005];
//int tree2[600005],
int a2[200005];
void push(ll index,ll mini, ll maxi){
    ll mid=(mini+maxi)/2;
    if(lazy[index]!=0)tree[2*index]=(lazy[index]%2)*(mid+1-mini);
    if(lazy[index]!=0)lazy[2*index]=lazy[index];
    if(lazy[index]!=0)tree[2*index+1]=(lazy[index]%2)*(maxi-mid);
    if(lazy[index]!=0)lazy[2*index+1]=lazy[index];
    lazy[index]=0;
}
void build(ll mini , ll maxi , ll index){
    if(mini==maxi){tree[index]= a[mini]; return ;}
    ll mid=(mini+maxi)/2;
    build(mini, mid , 2*index);
    build(mid+1 ,maxi,2*index +1);
    tree[index]=tree[2*index ] + tree[2*index +1];
    return ;
}

void update(ll mini ,ll maxi, ll treeindex , ll l ,ll r, ll val){
    if(mini==l && maxi==r){tree[treeindex] = (maxi+1-mini)*(val%2); lazy[treeindex]=val; return ;}
    ll mid=(mini+maxi)/2;
    //cout<<mid<<" ";
    push(treeindex, mini, maxi);
    if(mid>=l){update(mini, mid , 2*treeindex , l, min(mid,r) , val); }
    if(mid+1<=r) update(mid+1 , maxi , 2*treeindex+1 , max(mid+1, l), r , val);
    tree[treeindex]= tree[treeindex*2] + tree[2*treeindex +1];
}

ll minval(ll mini, ll maxi,  ll l ,ll r , ll index){
    if(l > r)return 0;
    if(l==mini && r== maxi){return tree[index];  }
    push(index, mini, maxi);
    ll mid= (mini+maxi)/2;
    return  minval(mini, mid , l ,min(r,mid) , 2*index) + minval(mid+1 , maxi , max(l,mid+1), r, 2*index+1) ;
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
    cin>>t;
    //t=1;
    while(t--){
        cin>>n>>q;
        fo(i,3*n+5){tree[i]=0; lazy[i]=0; }
        string s;
        cin>>s;
        string s1;
        cin>>s1;
        ll c1=0,c2=0;
        fo(i,n)if(s[i]=='1')c1++;
        fo(i,n){if(s1[i]=='0')a[i]=0; else a[i]=1;}
        fo(i,n){if(s[i]=='0')a2[i]=0; else a2[i]=1;}
        //build2(0,n-1,1);
        build(0,n-1, 1);
        //cout<<tree[1]<<endl;
        ll l[q],r[q];
        fo(i,q)cin>>l[i]>>r[i];
        //if(c1!=0 && c1!=n){cout<<"NO"<<endl; continue;}
        flag=1;
        for(int i=q-1;i>=0;i--){
            ll c1 = minval(0,n-1, l[i]-1, r[i]-1, 1);
            if((r[i]-l[i]+1)%2 ==0){if(c1*2 == r[i]-l[i]+1){flag=0; break;}}
            ll val=1;
            if(c1*2 < r[i]-l[i]+1) val=2;
            //cout<<c1<< " "<<val<< " "<<flag<<endl;
            update(0,n-1,1,l[i]-1, r[i]-1, val);
            //if(t==1){fo(i,n)cout<<minval(0,n-1, 0,i,1)<<" "; cout<<endl;}
        }
        ll pre[n];
        pre[0]=a2[0];
        fo1(i,n-1){pre[i]=pre[i-1] + a2[i];}
        ll temp= pre[r[0]-1];
        if(l[0]>1)temp-=pre[l[0]-2];
        //if(temp !=0 && temp!= r[0]-l[0]+1)flag=0;
        //else flag=0;
        fo(i,n)if(pre[i] != minval(0,n-1, 0,i,1) ){flag=0;  } 
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}