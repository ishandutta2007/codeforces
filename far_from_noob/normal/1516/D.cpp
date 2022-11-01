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
pll p[100001][20];
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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<1005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=1000){
            ifused[j]=1;
            j+=i;
        }
    }
    t=1;
    while(t--){
        cin>>n>>q;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll par[n+5];
        ll count[100005] ={0};
        ll  ans[n];
        ll temp=0;
        vll v[n+1];
        fo(i,n){
            while(temp<n){
                ll val= a[temp];
                ll ff=0;
                for(int j=0;prime[j]<350;j++){
                    ll f=0;
                    while(val%prime[j] ==0){
                        f=1;val/=prime[j];
                    }
                    //count[j]+=f;
                    if(f==1){
                        if(count[prime[j]]>0)ff=1;
                        v[temp].pb(prime[j]);
                    }
                }
                if(val>1){if(count[val]>0)ff=1; v[temp].pb(val);}

                if(ff==0){
                    fo(j,v[temp].size())count[v[temp][j]]++;
                    
                    temp++;
                }
                else break;
            }
            ans[i]=temp-1;
            //cout<<ans[i]<<endl;
            fo(j,v[i].size())count[v[i][j]]--;
                    
        }
        //break;
        
        fo(i,20){
            fo(j,n){
                if(j+ (ll)pow(2,i)-1>=n)continue;
                if(i==0){
                    p[j][0]= mp(ans[j],1);
                    //cout<<ans[j]<<endl;
                }
                else{
                    //cout<<j<<endl;
                    if(p[j][i-1].fi - j+1 >= (ll)pow(2,i)){p[j][i]= p[j][i-1]; continue;}
                    ll curr = p[j][i-1].fi, step = p[j][i-1].se;
                    while(curr- j +1<(ll)pow(2,i)){
                        ll val = (ll)pow(2,i) - curr + j-1;
                        ll zz= log2(val);
                        //cout<<j<<" "<<curr<<" " <<val<<endl;

                        step+= p[curr+1][zz].se;
                        curr = p[curr+1][zz].fi;
                        //cout<<j<<" "<<p[curr+1][zz].fi<<endl;
                        //break;
                    }
                    p[j][i]= mp(curr, step);
                }
            }
        }
        //break;
        //cin>>q;
        //fo(i,3)cout<<p[0][i].fi<<" "<<p[0][i].se<<endl;
        fo(i,q){
            ll l,r;cin>>l>>r; l-- ;r--;
            //cout<<l<<" " <<r<<endl;
            //break;
            ll curr= l-1, step = 0;
            while(curr<r){
                        ll val = r-curr;
                        ll zz= log2(val);

                        step+= p[curr+1][zz].se;
                        curr = p[curr+1][zz].fi;
                        //cout<<curr<<endl;
                        //break;
                    }
                    cout<<step<<endl;
        }
        




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}