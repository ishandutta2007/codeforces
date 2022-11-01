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
        set<ll>s1,s2;
        s1.insert(-1), s2.insert(-1);
        fo(i,n)s1.insert(i),s2.insert(i);

        pll p1[n],p2[n];
        fo(i,n){
            cin>>k;
            p1[i]=mp(k,i);
            //p2[i]=mp(k,i)
        }
        fo(i,n){
            cin>>k;
            //p1[i]=mp(k,i);
            p2[i]=mp(k,i);
        }
        sort(p1,p1+n);sort(p2,p2+n);
        map<ll,ll>r1,r2;

        fo(i,n)r1[p1[i].se]=i;
        fo(i,n)r2[p2[i].se]=i;

        ll ans[n];
        fo(i,n)ans[i]=0;

        queue<ll>q;
        ll ind = p1[n-1].se;
        q.push(p1[n-1].se);
        ans[ind]=1;
        s1.erase( s1.lower_bound(r1[ind]) );s2.erase( s2.lower_bound(r2[ind]) );

        while(q.size()>0){
            ll ind = q.front();
            q.pop();
            //if(ind==0)break;

            while(1){
                auto it = s1.end();it--;

                if(*it == -1)break;
                if(*it < r1[ind])break;

                ll val = p1[ (*it) ].se;
                q.push(val);
                //cout<<val<<endl;
                ans[val]=1;
                s1.erase( s1.lower_bound(r1[val]) );
                s2.erase( s2.lower_bound(r2[val]) );
                //it--;

            }

            
            while(1){
                auto it1 = s2.end(); it1--;
                //if(ind!=3)break;
                if(*it1 == -1)break;
                if(*it1 < r2[ind])break;
                //cout<<*it1<<r2[ind];
                //break;
                ll val = p2[ (*it1) ].se;
                //cout<<val;
                //break;
                q.push(val);
                //break;
                //cout<<val<<endl;
                //break;
                ans[val]=1;
                s1.erase( s1.lower_bound(r1[val]) );
                s2.erase( s2.lower_bound(r2[val]) );
                //break;
                //it1--;
                //break;
            }
        }
        fo(i,n)cout<<ans[i];
        cout<<endl;


        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}