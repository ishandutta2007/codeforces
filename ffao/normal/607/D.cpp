#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
const int mod = 1000000007;


template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}

struct node {
    int curmult = 1;
    int val;
};

node tree[1610000];

int query(int x, int y, int i=1, int st=1, int ed=n) {
    if (x <= st && ed <= y) return (tree[i].val * 1ll * tree[i].curmult) % mod;
    if (st > y || ed < x) return 0;

    //printf("%d %d %d %d %d\n", i, tree[i].val, tree[i].curmult, st, ed);
    int md = (st+ed)/2;
    int k = (query(x,y,2*i,st,md) + query(x,y,2*i+1,md+1,ed)) % mod;
    return (k * 1ll * tree[i].curmult) % mod;
}

void pt(int x, int y, int i=1, int st=1, int ed=n) {
    printf("%d %d %d %d %d\n", i, tree[i].val, tree[i].curmult, st, ed);
    if (st == ed) return;

    int md = (st+ed)/2;
    pt(x,y,2*i,st,md);
    pt(x,y,2*i+1,md+1,ed);
}

int query_mul(int x, int i=1, int st=1, int ed=n) {
    if (x <= st && ed <= x) return tree[i].curmult;
    if (st > x || ed < x) return 1;

    int md = (st+ed)/2;
    
    int bb = (query_mul(x,2*i,st,md) * 1ll * query_mul(x,2*i+1,md+1,ed)) % mod;
    return (bb * 1ll * tree[i].curmult) % mod;
}

void wake_up(int x, int d, int i=1, int st=1, int ed=n) {
    if (x <= st && ed <= x) {
        tree[i].val = (tree[i].val + d) % mod;
        return;
    }
    if (st > x || ed < x) return;

    int md = (st+ed)/2;
    wake_up(x,d,2*i,st,md);
    wake_up(x,d,2*i+1,md+1,ed);

    tree[i].val = (tree[2*i].val * 1ll * tree[2*i].curmult + tree[2*i+1].val * 1ll * tree[2*i+1].curmult) % mod;
}

void wake_mul(int x, int y, int d, int i=1, int st=1, int ed=n) {
    if (x <= st && ed <= y) {
        tree[i].curmult = (tree[i].curmult * 1ll * d) % mod;
        return;
    }
    if (st > y || ed < x) return;

    int md = (st+ed)/2;
    wake_mul(x,y,d,2*i,st,md);
    wake_mul(x,y,d,2*i+1,md+1,ed);

    tree[i].val = (tree[2*i].val * 1ll * tree[2*i].curmult + tree[2*i+1].val * 1ll * tree[2*i+1].curmult) % mod;
}

int q;
int values[210000];
int par[210000];
int lt[210000];
int rt[210000];
int curmult[210000];
vector<int> adj[210000];

pair<int, int> queries[210000];

int curpre;

void dfs(int v) {
    lt[v] = curpre++;

    for (int x : adj[v]) {
        dfs(x);
    }

    rt[v] = curpre-1;
}

int main() {
    scanf("%d %d", &values[1], &q);
    n = 1;
    curmult[1] = 1;

    for (int i = 0; i < q; i++) {
        int typ;
        scanf("%d", &typ);

        if (typ == 1) {
            int p,v;
            scanf("%d %d", &p, &v);
            values[++n] = v;
            adj[p].push_back(n);
            queries[i] = {1, p};
            par[n] = p;
        }
        else {
            int v;
            scanf("%d", &v);
            queries[i] = {2, v};
        }
    }

    curpre = 1;
    dfs(1);

    wake_up(lt[1], values[1]);
    //pt(1,5);

    int added = 1;
    for (int i = 0; i < q; i++) {
        if (queries[i].first == 1) {
            added++;
            curmult[added] = 1;
            curmult[queries[i].second]++;

            wake_up(lt[added], values[added]);
            wake_mul(lt[queries[i].second], rt[queries[i].second], (curmult[queries[i].second] * 1ll * modInv(curmult[queries[i].second] - 1, mod)) % mod);
            //printf("\n");
            //pt(1,5);
        }

        else {
            int v = queries[i].second;

            //printf("%d\n", query(5, 5));
            int tot = query(lt[v], rt[v]);

            long long mm = 1;
            if (v != 1) mm = query_mul(lt[par[v]]);

            //printf("mm = %lld\n", mm);

            printf("%lld\n", tot * 1ll * modInv(mm, (ll)mod) % mod);
        }
    }
}