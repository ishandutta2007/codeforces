#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const int maxn = 200005;
const int depth = 31;

struct Node{
    int l, r, v;
    Node(){
        l = r = v = 0;
    }
};

Node trie[maxn*depth];
int ptr, a[maxn], root[maxn];
ll ans = 0;

int update(int v, int k){
    int nv = ptr++;
    trie[nv] = trie[v];
    int ret = nv;
    trie[nv].v++;
    for(int i = 29; i >= 0; i--){
        if((k>>i)&1){
            trie[nv].r = ptr++;
            trie[trie[nv].r] = trie[trie[v].r];
            nv = trie[nv].r;
            v = trie[v].r;
        }else{
            trie[nv].l = ptr++;
            trie[trie[nv].l] = trie[trie[v].l];
            nv = trie[nv].l;
            v = trie[v].l;
        }
        trie[nv].v++;
    }
    return ret;
}

int query(int vl, int vr, int k){
    int ret = 0;
    for(int i = 29; i >= 0; i--){
        if((k>>i)&1){
            if(trie[trie[vl].r].v < trie[trie[vr].r].v){
                vl = trie[vl].r;
                vr = trie[vr].r;
                ret |= (1<<i);
            }else{
                vl = trie[vl].l;
                vr = trie[vr].l;
            }
        }else{
            if(trie[trie[vl].l].v < trie[trie[vr].l].v){
                vl = trie[vl].l;
                vr = trie[vr].l;
            }else{
                vl = trie[vl].r;
                vr = trie[vr].r;
                ret |= (1<<i);
            }
        }
    }
    return ret^k;
}

inline bool isset(int x, int d){
    return (x>>d)&1;
}

void add(int l1, int r1, int l2, int r2){
    if(l1 > r1 || l2 > r2)return;
    if(r1 - l1 > r2 - l2){
        swap(l1, l2);
        swap(r1, r2);
    }
    int ret = (1<<30);
    for(int i = l1; i <= r1; i++){
        ret = min(ret, query(root[l2-1], root[r2], a[i]));
    }
    ans += ret;
}

void compute(int l, int r, int d, int val){
    if(d == -1 || l >= r)return;
    if(isset(a[l], d) || (!isset(a[r], d))){
        int nval = val;
        if(isset(a[l], d))nval |= (1<<d);
        compute(l, r, d - 1, nval);
        return;
    }
    int m = lower_bound(a + l, a + r + 1, val|(1<<d)) - a;
    // cout<<l<<" "<<r<<" "<<m<<" "<<d<<" "<<val<<endl;
    compute(l, m - 1, d - 1, val);
    compute(m, r, d - 1, (val|(1<<d)));
    add(l, m - 1, m, r);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    ptr = 1;
    root[0] = 0;
    for(int i = 1; i <= n; i++){
        root[i] = update(root[i-1], a[i]);
    }
    compute(1, n, 29, 0);
    cout<<ans<<endl;
}