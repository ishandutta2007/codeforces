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
        cin>>n>>m;
        ll a,b,c;
        cin>>a>>b>>c;
        ll p[m];
        fo(i,m)cin>>p[i];
        vll v[n+1];
        ll disa[n+1],disb[n+1],disc[n+1];
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        queue<ll>q;
        map<ll,ll>m1;
        m1[a]=1;
        q.push(a);
        disa[a]=0;
        while(q.size()>0){
            ll node=q.front();
            q.pop();
            fo(i,v[node].size()){
                if(m1[v[node][i]]==1)continue;
                m1[v[node][i]]=1;
                q.push(v[node][i]);
                disa[v[node][i]]=disa[node]+1;
            }
        }
        map<ll,ll>m2;
        m2[b]=1;
        q.push(b);
        disb[b]=0;
        while(q.size()>0){
            ll node=q.front();
            q.pop();
            fo(i,v[node].size()){
                if(m2[v[node][i]]==1)continue;
                m2[v[node][i]]=1;
                q.push(v[node][i]);
                disb[v[node][i]]=disb[node]+1;
            }
        }
        map<ll,ll>m3;
        m3[c]=1;
        q.push(c);
        disc[c]=0;
        while(q.size()>0){
            ll node=q.front();
            q.pop();
            fo(i,v[node].size()){
                if(m3[v[node][i]]==1)continue;
                m3[v[node][i]]=1;
                q.push(v[node][i]);
                disc[v[node][i]]=disc[node]+1;
            }
        }
        sort(p,p+m);
        ll presum[m+1];
        ll tsum=0;
        presum[0]=0;
        fo(i,m){
            presum[i+1]=p[i]+tsum;
            tsum=presum[i+1];
            //cout<<presum[i+1]<<" "<<p[i]<<" ";
        }
        ll ans=1e18;
        //fo1(i,n)cout<<disb[i]<<" ";cout<<endl;<<disa[i]<<disb[i]<<disc[i]
        fo1(i,n){
            ll kk=disa[i]+disb[i]+disc[i];
            if(kk>m)continue;
            ans=min(ans, presum[kk]+presum[disb[i]]);
            //cout<<presum[kk]<<" "<<presum[disb[i]]<<ans<<" ";
        }
        cout<<ans<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}