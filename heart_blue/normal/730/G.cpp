#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ld eps = 1e-9;
const int inf = mod;
const db PI = atan(1)*4;
template<typename T>
inline int sign(const T&a){if(a<0)return -1;if(a>0)return 1;return 0;}


template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

deque<PLL>q;
bool valid(PLL a){
    return a.se>=a.fi;
}

void upd(PLL a){
    if(valid(a))q.PB(a);
}
int main(){
    q.PB(MP(1,1000000000000));
    int n;in(n);
    vector<PLL>alr;
    REP(i,0,n){
        ll start,len;
        cin>>start>>len;
        bool clash = 0;
        for(auto i:alr){
            if(max(start,i.fi)<=min(start+len-1,i.fi+i.se-1))clash = 1;
        }
 /*       dbg(clash)
        dbg("range");
        for(auto i:q){
            cout<<i.fi<<' '<<i.se<<endl;
        }
                dbg("rangeend");
*/
        if(!clash){
            REP(i,0,sz(q)){
                if(start>=q[i].fi && start<=q[i].se && max(start,q[i].fi)+len-1<=q[i].se){
                    PLL cur = q[i];
                    cout<<start<<' '<<start+len-1<<endl;
                    alr.PB(MP(start,len));

                    if(start>=q[i].fi){                    
                        swap(q[i],q.back());
                        q.pop_back();
                        upd(MP(cur.fi,start-1));
                        upd(MP(start+len,cur.se));
                    }else{
                        swap(q[i],q.back());
                        q.pop_back();
                        upd(MP(cur.fi+len,cur.se));
                    }
                    break;
                }
            }
        }else{
            REP(i,0,sz(q)){
                if(q[i].fi+len-1<=q[i].se){
                    PLL cur = q[i];
                    alr.PB(MP(q[i].fi,len));

                    cout<<q[i].fi<<' '<<q[i].fi+len-1<<endl;
                    swap(q[i],q.back());
                    q.pop_back();
                    upd(MP(cur.fi+len,cur.se));
                    break;
                }
            }
        }             
        sort(all(q));

    }
    return 0;
}