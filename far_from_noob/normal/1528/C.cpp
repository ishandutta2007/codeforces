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
vll v1[300005],v2[300005];
ll in[300005],out[300005];
set<pll>s;
ll maxans;
pll ins[300005],era[300005];ll tim;
void dfs1(ll node, ll root){
    in[node]= tim;
    tim++;
    fo(i,v2[node].size()){
        if(v2[node][i]== root)continue;
        dfs1(v2[node][i], node);
    }
    out[node]=tim;
    tim++;
}
void dfs(ll node, ll root){
    //cout<<node<<" "<<s.size()<<endl;
    pll p = mp(in[node] , 0);
    auto it= s.lower_bound(p);
    pll p2= *it;
    auto it2= it;
    it2--;
    pll p3=*it2;
    if(p2.se < out[node]){
        ins[node] =mp(-1,-1);
        era[node]= mp(-1,-1);
    }
    else if(p3.se> out[node]){
        era[node]= p3;
        ins[node]=(mp(in[node], out[node]));
        s.erase(it2);
        s.insert(mp(in[node], out[node]));
    }
    else{
        s.insert(mp(in[node], out[node]));
        era[node]= mp(-1,-1);
        ins[node]=(mp(in[node], out[node]));
    }
    maxans=max(maxans, s.size());
    //cout<<node<<" "<<maxans<<endl;
    //cout<<node<<" "<<s.size()<<endl;
    fo(i,v1[node].size()){
        if(v1[node][i]== root)continue;
        dfs(v1[node][i], node);
    }
    if(era[node].fi != -1){
        s.insert(era[node]);
    }
    if(ins[node].fi !=-1){
        auto it= s.lower_bound(ins[node]);
        s.erase(it);
    }

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
        cin>>n;
        fo(i,n+1)v1[i].clear(),v2[i].clear();
        for(int i=2;i<=n;i++){
            cin>>m;
            v1[i].pb(m);
            v1[m].pb(i);
        }
        for(int i=2;i<=n;i++){
            cin>>m;
            v2[i].pb(m);
            v2[m].pb(i);
        }
        tim=1;
        s.clear();    
        s.insert(mp(-2 , -2));
        s.insert(mp(1e9 , 1e9));
        maxans=2;
        dfs1(1,1);

        //fo1(i,n)cout<<in[i] <<" "<<out[i]<<endl;
        //cout<<endl;
        dfs(1,1);
        //cout<<maxans<<endl;
        cout<<maxans-2<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}