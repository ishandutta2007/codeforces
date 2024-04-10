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

int n;
vector<int>v;
bool check(int c){
    int l=0,r=0;
    REP(i,0,sz(v)){
        l+=v[i]-c;
        if(v[i]<c)return false;
        r = max(r,v[i]-c);
    }
    l-=r;
    if(l<r)return false;
    return true;
}

void pp(){
            REP(i,0,n){
            cout<<v[i]<<' ';
        }
        cout<<endl;

}
void pr(int a,int b,int c = -1){
    REP(i,0,n){
        if(i==a||i==b||i==c){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;
}
bool temp[110];
void process(const int ans){
    if(ans == 0){
        vector<string>aaa;
        while(v[0]){
            string cur = "11";
            REP(j,2,sz(v)){
                cur+="0";
            }
            aaa.PB(cur);
            v[0]--;
            v[1]=max(0,v[1]-1);
        }
        REP(i,1,sz(v)){
            while(v[i]){
                string cur = "";
                REP(j,0,sz(v)){
                    cur+="0";
                }  
                cur[0]='1';
                cur[i]='1';
                aaa.PB(cur);
                v[i]--;
            }
        }
        cout<<sz(aaa)<<endl;
        for(auto i:aaa){
            cout<<i<<endl;
        }
        return;
    }
    int two,three;
    int res = 0;
    REP(i,0,sz(v))res+=v[i]-ans;
    for(two = res/2;two>=0;two--){
        if((res-two*2)%3==0){
            three = (res-two*2)/3;
            break;
        }
    }
    cout<<two+three<<endl;
    priority_queue<PII>pq;    
    REP(i,0,n)pq.push(MP(v[i],i));
    REP(i,0,two){   
        PII a,b;
        a = pq.top();pq.pop();
        b = pq.top();pq.pop();
        pr(a.se,b.se);
        pq.push(MP(a.fi-1,a.se));
        pq.push(MP(b.fi-1,b.se));
    }
    REP(i,0,three){
        PII a,b,c;
        a = pq.top();pq.pop();
        b = pq.top();pq.pop();
        c = pq.top();pq.pop();
        pr(a.se,b.se,c.se);
        pq.push(MP(a.fi-1,a.se));
        pq.push(MP(b.fi-1,b.se));
        pq.push(MP(c.fi-1,c.se));

    }

}
int main(){
    cin>>n;
    REP(i,0,n){
        int c;cin>>c;v.PB(c);
    }
    int ans = 0;
    REP(i,0,200){
        if(check(i))ans = i;
    }
    cout<<ans<<endl;
    process(ans);
    return 0;
}