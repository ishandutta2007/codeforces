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
vll v[100000];
map<ll, ll>grundy;
ll findgrundy(vll vect){
    ll sum=0;
    fo(i,vect.size())sum+=(1<<vect[i]);
    if(grundy[sum]>0)return grundy[sum]-1;
    //cout<<l;
    ll l=vect.size();
    //fo(i,l)cout<<vect[i];cout<<endl;
    ll flag=0;
    fo(i,l)if(vect[i]!=0)flag=1;
    if(flag==0){grundy[sum]=1; return 0;}
    ll temp=0;
    //vll mex;
    ll mex[50];
    fo(i,50)mex[i]=0;
    ll vj=vect[l-1];
    fo1(i,vj){
        while(i>vect[temp])temp++;
        //cout<<temp<<endl;
        vll vv;
        fo(j,temp)vv.pb(vect[j]);
        for(int j=temp;j<l;j++){
            vv.pb(vect[j]-i);
        }
        sort(all(vv));
        vll vk;
        vk.pb(vv[0]);
        fo1(j,vv.size()-1){
            if(vv[j]!=vv[j-1])vk.pb(vv[j]);
        }
        ll kk =findgrundy(vk);
        //cout<<i<<endl;
        mex[kk]=1;
        
    }
    //cout<<2222;
    ll val=0;
    while(1){
        if(mex[val]==0){break;}
        else val++;
    }
    grundy[sum]=val+1;
    return val;
 
 
 
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
    vector<ll>prime;
    map<ll ,ll>ifused;
    for(ll i=2;i<100005;i++){
        if(ifused[i]==1)continue;
        ll j=i;
        prime.push_back(i);
        while(j<=100005){
            ifused[j]=1;
            j+=i;
        }
    }
    t=1;
    while(t--){
        cin>>n;
        ll a[n];
        map<ll,ll>m1;
        map<ll , ll >index;
        ll temp=1;
        fo(j,n){
            cin>>a[j];
            ll kk =a[j];
            for(int i=0; prime[i]<100000;i++){
                ll cc=0;
                while(kk%prime[i]==0){
                    kk/=prime[i];
                    cc++;
                }
                if(cc>0){
                    if(index[prime[i]]==0)index[prime[i]]=temp, temp++;
                    v[index[prime[i]]].pb(cc);
                }
            }
            if(kk>1){
                if(index[kk]==0)index[kk]=temp,temp++;
                v[index[kk]].pb(1);
            }
        }
        ll ans=0;
        fo1(i,temp-1){
            sort(all(v[i]));
            vll vk;
            vk.pb(v[i][0]);
            fo1(j,v[i].size()-1){
                if(v[i][j]!=v[i][j-1])vk.pb(v[i][j]);
            }
            ans=ans^findgrundy(vk);
        }
        if(ans==0)cout<<"Arpa";
        else cout<<"Mojtaba";
 
 
 
 
        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}