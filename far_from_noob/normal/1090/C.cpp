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
        cin>>n>>m;

        set<ll>s[m+1];
        set<ll>v[n];
        ll tot=0;
        fo(i,n){
            cin>>k; tot+=k;
            fo(j,k){cin>>q; v[i].insert(q);}
        }

        ll siz = tot/n;
        ll cnt = tot%n;
        //cout<<cnt<<endl;
        map<ll,ll>mk;

        fo(i,n){
            if(v[i].size()>siz){
                if(cnt==0)continue;
                else{
                    v[i].erase(v[i].begin());
                    cnt--;
                    mk[i]=1;
                }
            }
        }
        //if(n==500){cout<<siz<<endl; break;}
        //cout<<v[1].size()<<endl;

        set<ll>curr;
        curr.insert(mod);
        map<ll,ll>m1;


        vector<pair<pll,ll>>ans;
        fo(i,n){
            if(v[i].size()>siz){
                auto it= v[i].begin();
                while(it!= v[i].end()){
                    ll p = *it;
                    if(m1[p]==0){m1[p]=1; curr.insert(p); }
                    it++;
                    s[p].insert(i);
                }
            }
        }
        //cout<<v[1].size()<<endl;

        //cout<<*s[1].begin()<<endl;

        //cout<<siz<<endl;
        ll tempsiz = siz;
        
        fo(i,n){
            map<ll,ll>temp;
            auto it1 = v[i].begin();
            while(it1!=v[i].end()){temp[(*it1)]++; it1++; }
            auto it = curr.begin();
            //cout<<*s[1].begin()<<endl;


            //if(i == 7){ break;}
            //cout<<v[i].size()<<endl; 
            //continue;
            tempsiz=siz;
            if(cnt >0 && mk[i]==0 ){tempsiz++; cnt--; }

            while(v[i].size()<tempsiz && it!=curr.end()){
                //if(i==7)break;
                ll col = *it;
                it++;

                if(temp[col]==1)continue;

                auto itr = s[col].begin();
                ll num = *itr;
                ans.pb(mp(mp(num +1, i+1), col));
                //if(i==7){cout<<col<<*itr<<endl;break;}
                s[col].erase(itr);
                v[num].erase(v[num].lower_bound(col));
                v[i].insert(col);
                if(s[col].size()==0)curr.erase(curr.lower_bound(col));
                if(v[num].size()==siz){
                    //cout<<num<<endl;
                    auto it2 = v[num].begin();
                    while(it2!=v[num].end()){
                        ll color = *it2;
                        s[color].erase(s[color].lower_bound(num));
                        if(s[color].size()==0){
                            if(*it == color)it++;
                            curr.erase(curr.lower_bound(color));
                        }
                        it2++;
                    }
                }
                //if(i==7)break;
            }
                        //break;
        }

        cout<<ans.size()<<endl;
        fo(i,ans.size())cout<<ans[i].fi.fi<< " "<<ans[i].fi.se<< " "<<ans[i].se<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}