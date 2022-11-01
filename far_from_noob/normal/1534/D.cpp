#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double

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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        map<ll,ll>m1;
        vector<pll>v;
        map<pll,ll>check;
        queue<ll>q;
        q.push(1);
        m1[1]=1;
        ll temp[n+1];
        while(q.size()>0){
            ll node= q.front();
            q.pop();
            cout<<"? "<<node<<endl;
            fo1(i,n)cin>>temp[i];
            vll vk1,vk2;
            if(node==1){
                ll c1=0,c2=0;
                fo1(i,n){
                    if(temp[i]%2==1){
                        if(temp[i]==1){
                            v.pb(mp(node,i));
                            check[mp(node,i)]=1;
                            check[mp(i,node)]=1;
                            vk1.pb(i);
                        }
                        c1++;
                    }
                    if(temp[i]%2==0 && temp[i]>0){
                        c2++;
                        if(temp[i]==2)vk2.pb(i);
                    }
                }
                if(c1<=c2){
                    fo(i,vk1.size()){
                        m1[vk1[i]]=1;
                        q.push(vk1[i]);
                    }
                }
                else{
                    fo(i,vk2.size()){
                        m1[vk2[i]]=1;
                        q.push(vk2[i]);
                    }
                }
            }
            else{
            fo1(i,n){
                if(temp[i]==1){
                    if(check[mp(node,i)]==0 )v.pb(mp(node, i));
                    check[mp(node,i)]=1;
                    check[mp(i,node)]=1;
                }
                if(temp[i]==2){
                    if(m1[i]==0){
                        m1[i]=1;
                        q.push(i);

                    }
                }
            }
            }
        }
        cout<<"! "<<endl;
        fo(i,n-1){
            cout<<v[i].fi<<" "<<v[i].se<<endl;
        }




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}