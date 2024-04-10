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


struct team{
    int ini,delta,id,used;
    bool operator<(const team&o)const{
        if(ini!=o.ini)return ini<o.ini;
        return id>o.id;
    }
};  
vector<team>v;
int main(){
    int n;cin>>n;
    REP(i,0,n){
        int a,b;
        cin>>a>>b;
        v.PB({a,b,i,0});
    }
    sort(all(v));
    reverse(all(v));
    int ans = 0;
    REP(i,0,n){
        REP(j,0,n){
            if(v[j].delta<0 && v[j].used ==0){
                v[j].used = 1;
                v[j].ini+=v[j].delta;
                int cur = j;
                while(cur+1<n&&v[cur]<v[cur+1]){
                    ans++;
                    swap(v[cur],v[cur+1]);cur++;
                }
                break;
            }
        }
    }       
    REP(i,0,n){
        RREP(j,n-1,0){
            if(v[j].delta>0 && v[j].used ==0){
                v[j].used = 1;
                v[j].ini+=v[j].delta;
                int cur = j;
                while(cur&&v[cur-1]<v[cur]){
                    ans++;
                    swap(v[cur],v[cur-1]);cur--;
                }
                break;
            }
        }
    }        
        
    cout<<ans;
    return 0;
}