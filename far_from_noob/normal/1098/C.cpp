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
vll v[100005];
ll h[100005];
ll par[100005];
ll sub[100005];

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
        ll s;
        cin>>n>>s;
        if(s<2*n-1 || s>(n+1)*n/2){cout<<"No"<<endl; continue;}
        cout<<"Yes"<<endl;
        if(s==(n+1)*n/2){fo(i,n-1)cout<<i+1<<" "; continue;}
        //cout<<(n+1)*n/2<<endl;
        ll l =1, r=n-1;
        while(l<r){
            k = (l+r)/2  + 1 ; 
            ll temp=2;
            queue<ll>q;
            q.push(1);
            h[1]=1;
            while(temp<=n){
                ll node = q.front();
                q.pop();
                fo(i,k){
                    if(temp<=n){
                        q.push(temp);
                        v[node].pb(temp);
                        par[temp]=node;
                        h[temp]=h[node]+1;
                        temp++;
                    }
                }
            }
            ll count=0;
            for(int i=n;i>=1;i--){
                sub[i]=1;
                fo(j,v[i].size())sub[i]+=sub[v[i][j]];
                count+=sub[i];
            }
            //cout<<k<<count<<s<<endl;
            //if(k==2)cout<<count<<endl;
            if(count>s)l=k;
            else r=k-1; 
            fo(i,n+1){v[i].clear(); h[i]=0; par[i]=0;}
        }
        k=l;//cout<<k<<endl; fo(i,n-1)cout<<par[i+2]<< " ";
        //break;
        ll temp=2;
            queue<ll>q;
            q.push(1);
            h[1]=1;
            while(temp<=n){
                ll node = q.front();
                q.pop();
                fo(i,k){
                    if(temp<=n){
                        q.push(temp);
                        v[node].pb(temp);
                        par[temp]=node;
                        h[temp]=h[node]+1;
                        temp++;
                    }
                }
            }
        ll curr=0;
        for(int i=n;i>=1;i--){
                sub[i]=1;
                fo(j,v[i].size())sub[i]+=sub[v[i][j]];
                curr+=sub[i];
        }
        //cout<<k<<endl; fo(i,n-1)cout<<par[i+2]<< " ";
        //break;
        queue<ll>qin, qout;
        qin.push(1);

        for(int i=n;i>0;i--)if(sub[i]==1 )qout.push(i);

        while(curr>s){
            ll node = qout.front();
            qout.pop();

            ll newp = qin.front();
            if(curr -s <  h[node] - h[newp]-1 ){
                fo1(i,n){
                    if(-1*h[i] == curr-s -h[node]+1 && v[i].size()!= k+1){par[node] = i; }
                }
                break;
            }
            curr -= h[node] - h[newp]-1;
            v[newp].pb(node);
            if(v[newp].size() == k+1){
                fo(j,k+1)qin.push(v[newp][j]);
                qin.pop();
            }

            h[node] = h[newp]+1;

            sub[par[node]]--;
            v[par[node]].pop_back();
            if(v[par[node]].size() == 0)qout.push(par[node]);
            par[node]=newp;
            //cout<<qin.size()<< " "<< qout.size()<<endl;
            //if(qout.front() == 69)break;
        }
        fo(i,n-1)cout<<par[i+2]<< " ";




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}