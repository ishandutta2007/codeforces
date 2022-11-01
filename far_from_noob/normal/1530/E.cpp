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
        string s;cin>>s;
        char c='z';
        n=s.size();


        ll count[26]={0};
        fo(i,n)count[s[i]-'a']++;

        ll temp=-1;
        fo(i,26){

            if(count[i]==1){temp=i; break;}

        }
        if(temp>=0){
            cout<<(char)('a'+temp);
            fo(i,26){
                if(temp!=i){
                    fo(j,count[i])cout<<(char)('a'+i);
                }
            }
            cout<<endl;
            continue;
        }


        fo(i,n)c= min(s[i],c);
        vector<char> v1,v2;
        fo(i,n){
            if(s[i]==c)v1.pb(c);
            else v2.pb(s[i]);
        }
        sort(all(v2));

        if(v1.size()<=2){
        fo(i,v1.size())cout<<v1[i];
        fo(i,v2.size())cout<<v2[i];
        }
        else{
            if(v2.size()==0){cout<<s<<endl; continue;}
            if(v1.size()<=v2.size()+2){
                cout<<c<<c;
                //cout<<v1.size()<< v2.size()<<endl;
                fo(i,v1.size()-2){
                    cout<<v2[i]<<v1[i];
                }
                for(int i=v1.size()-2;i<v2.size();i++)cout<<v2[i];

            }
            else{
                cout<<c;cout<<v2[0];
                ll cc=0;
                fo(i,v2.size())if(v2[i]==v2[0])cc++;
                if(cc== 1 && v2.size()==1){
                    fo1(i,v1.size()-1)cout<<c;
                }

                else if(cc==v2.size() ){
                    fo1(i,v2.size()-1)cout<<  v2[i];
                fo1(i,v1.size()-1)cout<<c;
                
                }
                else{
                    fo1(i,v1.size()-1)cout<<c;
                    cout<<v2[cc];
                    fo(i,cc-1)cout<<v2[0];
                    for(int i= cc+1;i<v2.size();i++)cout<<v2[i];
                }
            }
        }
        cout<<endl;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}