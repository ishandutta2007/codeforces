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

struct store{
    int city,cnt,price;
    bool operator<(const store&o)const{
        return price<o.price;
    }
};
int n,m,w;
const int maxn = 5010;
store st[5010];
vector<int>adj[maxn];
int dis[maxn];
ll shovel;ll target;ll cost;

bool check(int t){
    ll c = 0;
    ll res = shovel;
    REP(i,0,w){
        if(dis[st[i].city]>t)continue;
        ll purchase = min(res,(ll)st[i].cnt);
        c+=purchase*st[i].price;
        res-=purchase;
        if(c>cost)return false;
    }
    if(res||c>cost)return false;
    return true;

}
void solve(){
    mst(dis,0x3f);
    dis[target] = 0;
    queue<int>q;
    q.push(target);
    while(!q.empty()){
        int f= q.front();q.pop();
        REP(j,0,sz(adj[f])){
            if(dis[adj[f][j]]==dis[0]){
                dis[adj[f][j]] = dis[f]+1;
                q.push(adj[f][j]);
            }
        }
    }
    int l = 0,r = 5010;
    while(l<r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if(l>5000){
        printf("-1\n");
    }else{
        iout(l);
    }
}
int main(){
    in(n);in(m);
    REP(i,0,m){
        int u,v;in(u);in(v);
        adj[u].PB(v);
        adj[v].PB(u);
    }
    in(w);
    REP(i,0,w){
        in(st[i].city);
        in(st[i].cnt);
        in(st[i].price);
    }
    sort(st,st+w);
    int q;in(q);
    REP(i,0,q){
        in(target);in(shovel);in(cost);
        solve();
    }
    return 0;
}