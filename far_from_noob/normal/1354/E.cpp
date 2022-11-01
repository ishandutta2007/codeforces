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
vll v[5005];
ll m1[5005];
void dfs(ll node, ll root){
    fo(i,v[node].size()){
        if(m1[v[node][i]]==0){
            m1[v[node][i]]=1;
            dfs(v[node][i] , i);
        }
    }
}
ll tot[5005];
ll cld[5005];
ll parent[5005];
void dfs2(ll node , ll root){
    parent[node]=root;
    fo(i,v[node].size()){
        if(m1[v[node][i]]==0){
            tot[root]++;
            if(m1[node]==2){
                m1[v[node][i]]=1;
            }
            else{
                m1[v[node][i]]=2;
                cld[root]++;   
            }
            dfs2(v[node][i], root);
        }
        else{
            if(abs(m1[node] - m1[v[node][i]]) !=1)flag=1;
        }
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
    //cin>>t;
    t=1;
    while(t--){
        flag=0;
        cin>>n>>m;
        ll n1,n2,n3;
        cin>>n1>>n2>>n3;
        fo(i,n+1)m1[i]=0;
        fo(i,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        vll subg;
        fo1(i,n){
            if(m1[i]==0){
                subg.pb(i);
                dfs(i,i);
            }
        }
        fo(i,n+1)m1[i]=0;
        fo(i,n+1)cld[i]=0,tot[i]=0;
        fo(i, subg.size()){
            m1[subg[i]]=2;
            tot[i]++;
            cld[i]++;
            dfs2(subg[i], i);
        }

        ll is[n+1][n+1];
        fo(i,n+1)fo(j,n+1)is[i][j]=0;
        is[0][0]=1;
        fo1(i,subg.size())fo(j,n+1){
            if(is[i-1][j]==1){
                is[i][j+cld[i-1]]=1;
                is[i][j+tot[i-1]-cld[i-1]]=1;
            }
        }
        //fo1(i,subg.size()){fo(j,n+1)cout<<is[i][j]<<" "; cout<<endl;}
        ll val[subg.size()];
        //if(flag==1)cout<<3434;
        if(flag==1 || is[subg.size() ][n2]==0){cout<<"NO"; return 0;}
        cout<<"YES"<<endl;
        ll temp=n2;
        for(int i=subg.size()-1; i>=0;i--){
            if(is [i] [ temp-cld[i]] ==1 && temp-cld[i]>=0){
                val[i]=0;
                temp-=cld[i];
            }
            else {
                val[i]=1;
                temp-=tot[i]-cld[i];
            }
        }
        ll cc=0;
        fo1(i,n){
            if(val[parent[i]]==0){
                if(m1[i]==2)cout<<2;
                else{
                    if(cc<n1)cout<<1,cc++;
                    else cout<<3;
                }
            }
            else{
                m1[i]++;
                if(m1[i]==2)cout<<2;
                else{
                    if(cc<n1)cout<<1,cc++;
                    else cout<<3;
                }
            }

        }








        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}