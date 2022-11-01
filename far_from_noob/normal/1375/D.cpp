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
        cin>>n;
        ll a[n];
        vll v[1005];
        ll count[1005]={0};
        fo(i,n){
            cin>>a[i];
            //v[a[i]].pb(i);
            count[a[i]]++;
        }
        vll ans;
        ll last=0;
        while(count[last]>0){last++; if(last==n)break;}
        while(1){
            //if(last>n)cout<<"ffff";
            if(last>=n){
                break;
            }
            ans.pb(last);
            count[a[last]]--;
            count[last]++;
            a[last]=last;
            //count[kk]--;
            last=0;
            while(count[last]>0){last++;}
            //cout<<last<<" ";
            //break;
        }
        //cout<<endl;
        ll mex=n;
        fo(i,n){
            if(a[i]==i)continue;
            flag=-1;
            fo(j,n){if(a[j]==i) flag=j; }
            if(flag==-1){
                mex=a[i];
                ans.pb(i);
                a[i]=i;
                continue;
            }
            ans.pb(flag);
            a[flag]=mex;
            ans.pb(i);
            mex=a[i];
            a[i]=i;
        }




        cout<<ans.size()<<endl;
        fo(i,ans.size())cout<<ans[i]+1<<" ";cout<<endl;

        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}