#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
//#define endl "\n"
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
        cin>>n;
        //cout<<n<<endl<<endl;
        vll v[n+1];
        fo(i,n-1){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll root;
        cout<<"? "<<n<<" ";
        fo(i,n)cout<<i+1<<" ";
        cout<<endl;
        cin>>root;
        ll dis;
        cin>>dis;
        vll d[n+1];
        queue<ll>q;
        ll parent[n+1];
        ll height[n+1];
        height[root]=0;
        parent[root]=root;
        q.push(root);
        while(q.size()){
            ll node=q.front();
            q.pop();
            fo(i,v[node].size()){
                if(v[node][i]==parent[node])continue;
                q.push(v[node][i]);
                height[v[node][i]]=height[node]+1;
                d[height[node]+1].pb(v[node][i]);
                parent[v[node][i]]=node;
            }
        }
        ll l=max(dis/2 - 1 ,0) , r=dis;
        d[0].pb(root);
        ll node;
        while(l!=r){
            ll mid=(l+r +1 )/2 ;
            //cout<<mid<<endl;
            if(d[mid].size()==0){r=mid-1; continue;}
            cout<<"? "<<d[mid].size()<<" ";
            fo(i,d[mid].size())cout<<d[mid][i]<<" ";
            cout<<endl;
            ll nn,val;
            cin>>nn>>val;
            if(val==dis){l=mid; node=nn;}
            else r=mid-1;
        }
        
        if(l==dis){
            cout<<"! "<<root<<" "<<node;
            cout<<endl;
            string s;
            cin>>s;
            continue;
        }
        ll val=node;
        while(height[val]!= dis-height[node]){
            val=parent[val];
        }
        cout<<"? "<<d[dis-l].size()-1<<" ";
        fo(i,d[dis-l].size()){if(d[dis-l][i]!=val)cout<<d[dis-l][i]<<" ";}
        cout<<endl;
        cin>>val>>k;
        cout<<"! "<<val<<" "<<node;
        cout<<endl;
        string s;
        cin>>s;
        continue;








        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}