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
        //cout<<(-4)%4;
        cin>>n>>k;
        ll kk=-1;
        ll val=-1;
        ll sum=0;
        ll def=mod;
        if(n<k*(k+1)/2){cout<<-1<<endl; continue; }
        //cout<<n-k*(k+1)/2<< " "<< k+1<<endl;
        if((n-k*(k+1)/2)%(k+1)==0){
            n=n-k*(k+1)/2;
            n=n/(k+1);
            vll v;
            if(n+0+k<10)v.pb(n),n=0;
            else v.pb(9-k); n-=9-k;
            while(n>0){
                if(n>=9)v.pb(9),n-=9;
                else v.pb(n),n=0;
            }
            fo(i,v.size())cout<<v[v.size()-1-i];
            cout<<endl;
            continue;
        }
        fo(i,20){
            ll temp=0;
            fo (j,10){
                if(j+k<10)continue;
                for(int l=0;l<=k;l++){
                    if(j+l<10)temp+=9*i + j+l;
                    else temp+=1 + (j+l)%10;
                }
                //if(i==2 && j==7)cout<<temp<<" ";
                if(temp<=n)if((n-temp)%(k+1)==0){val=j; kk=i;sum=temp;  }
                temp=0;
                if(val!=-1)break;
            }
            if(val!=-1)break;
        }
        //cout<<kk <<" "<< val<<" "<<sum<<endl;
        if(val ==-1)cout<<-1<<endl;
        else {
            //cout<<(n-sum)/(k+1)<<endl;
            n= (n-sum)/(k+1);
            vll v;
            if(n>0){
                v.pb(min(n,8));
                n-=min(n,8);
            }
            while(n>0){
                if(n>=9)v.pb(9),n-=9;
                else v.pb(n),n=0;
            }
            fo(i,v.size())cout<<v[v.size()-1-i];
            fo(i,kk)cout<<9;
            cout<<val<<endl;
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}