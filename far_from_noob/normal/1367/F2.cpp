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
        pll b[n];
        map<ll,ll>m1;
        fo(i,n)cin>>a[i],b[i]=mp(a[i],i);
        if(n==1){cout<<0<<endl; continue;}
        sort(b,b+n);
        ll index[n];
        ll temp=1;
        fo(i,n){
            if(m1[b[i].fi]==0)m1[b[i].fi]=temp,temp++;
        }
        vll v[n+1];
        fo(i,n){
            v[m1[a[i]]].pb(i);
        }
        ll ans=0;
        //fo(i,n)cout<<m1[a[i]]<<" ";
        fo1(i, temp-1){
            //if(i==6)cout<<2445456;
            ll last=v[i][v[i].size()-1];
            ll cc=v[i].size();
            ll j=i+1;
            for(;j<temp;j++){
                if(v[j][0]>last){
                    cc+=v[j].size();
                    last=v[j][v[j].size()-1];
                }
                else break;
            }
            //cout<<i<<" "<<cc<<endl;
            if(i>1)if(v[i-1][0]<v[i][0]){

                ll l=0, r=v[i-1].size()-1;
                while(l!=r){
                ll mid=(l+r)/2 +1;
                if(v[i-1][mid] < v[i][0]){l=mid;}
                else r=mid-1;

                }
                cc+= l+1;
            }
            //cout<<cc<<endl;
            if(j==temp){ans=max(ans, cc); break;}
            if(v[j][v[j].size()-1] <last ){
                ans=max(ans, cc  );
                i= (j-1);
                continue;
            }
            ll l=0, r=v[j].size()-1;
            while(l!=r){
                ll mid=(l+r)/2 ;
                if(v[j][mid] > last){r=mid;}
                else l=mid+1;

            }
            //if(i==6)cout<<last<<" ";
            ans=max(ans, cc + v[j].size()- l );
            i= (j-1);



        }
        for(int p=0;p<n-1;p++){
            int i = m1[a[p]];
            ll cc=0;
            if(1){

                ll l=0, r=v[i].size()-1;
                while(l!=r){
                ll mid=(l+r)/2 +1;
                if(v[i][mid] <= p){l=mid;}
                else r=mid-1;

                }
                cc+= l+1;
            }
            ll j=i+1;
            ll last=p;
            if(j==temp){ans=max(ans, cc); continue;}
            if(v[j][v[j].size()-1] <last ){
                ans=max(ans, cc  );
                //i= (j-1);
                continue;
            }
            ll l=0, r=v[j].size()-1;
            while(l!=r){
                ll mid=(l+r)/2 ;
                if(v[j][mid] > last){r=mid;}
                else l=mid+1;

            }
            //if(i==6)cout<<last<<" ";
            ans=max(ans, cc + v[j].size()- l );


        }

        cout<<n-ans<<endl;
        





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}