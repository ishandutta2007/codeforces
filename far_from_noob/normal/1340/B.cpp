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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>k;
        string s[n];
        fo(i,n)cin>>s[i];
        string a[10];
        a[0]="1110111";
        a[1]="0010010";
        a[2]="1011101";
        a[3]="1011011";
        a[4]="0111010";
        a[5]="1101011";
        a[6]="1101111";
        a[7]="1010010";
        a[8]="1111111";
        a[9]="1111011";
        ll ans[n];
        ll jj[n];
        ll count=0;
        //fo(i,7)if(a[7][i]==s[0][i])cout<<a[2][i];cout<<endl;
        fo(i,n){
            ll temp=10;
            ll val;
            for(int l=9;l>=0;l--){
                ll f=0;
                ll cc=0;
                fo(j,7){
                    //cout<<s[i][j]<<endl;
                    if(s[i][j]=='0' && a[l][j]=='1')cc++;
                    if(s[i][j]=='1' && a[l][j]=='0')f++;
                }
                if(f==0){
                    if(cc<temp){
                        temp=cc;
                        val=l;
                    }
                }
                //cout<<cc<<endl;
            }
            ans[i]=val;
            jj[i]=temp;
            count+=temp;
        }
        //o(i,n)cout<<ans[i]<<" ";
        //cout<<count;
        if(count>k){cout<<-1;return 0;}
        ll count9=0;
        fo(i,n){
            if(ans[i]==9){count9++; continue;}
            for(int l=9;l>=0;l--){
                ll f=0;
                ll cc=0;
                fo(j,7){
                    //cout<<s[i][j]<<endl;
                    if(s[i][j]=='0' && a[l][j]=='1')cc++;
                    if(s[i][j]=='1' && a[l][j]=='0')f++;
                }
                if(f==0){
                    if(cc+count-jj[i]<=k){
                        ans[i]=l;
                        count+=cc-jj[i];
                        jj[i]=cc;
                        if(l==9)count9++;
                        break;
                    }
                }
                //cout<<cc<<endl;
            }

        }
        //fo(i,n)cout<<ans[i]<<" ";
        for(int i=n-1;i>=0;i--){
            ll temp=0;
            ll val;
            for(int l=9;l>=0;l--){
                ll f=0;
                ll cc=0;
                fo(j,7){
                    //cout<<s[i][j]<<endl;
                    if(s[i][j]=='0' && a[l][j]=='1')cc++;
                    if(s[i][j]=='1' && a[l][j]=='0')f++;
                }
                if(f==0){
                    if(cc>temp && count+cc-jj[i]<=k){
                        ans[i]=l;
                        count+=cc-jj[i];
                        temp=cc;
                    }
                }
                //cout<<cc<<endl;
            }
            
        }
        if(k>count){cout<<-1; return 0;}
        ll c9=0;
        fo(i,n){
            cout<<ans[i];
        }





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}