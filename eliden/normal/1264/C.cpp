#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll MOD = 998244353;
struct T {
    ll prod_until;
    bool has;
    ll expval;
    ll expval_after;
    T(): prod_until(1), has(false), expval(0), expval_after(0) {}
};
void combine(T &target, const T &left, const T &right) {
    target.has = left.has || right.has;
    target.expval = (left.expval+right.expval +
                     (left.expval_after*((right.prod_until+MOD-1))))%MOD;
    target.expval_after = right.has?right.expval_after:
        ((right.expval+left.expval_after*right.prod_until)%MOD);
    target.prod_until = left.has?left.prod_until:
        ((left.prod_until*right.prod_until)%MOD);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n>>q;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    const ll LIM = 200;
    ll inv[LIM+1];
    inv[1] = 1;
    rep(i,2,LIM) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    int m = 1;
    while(n>m) m*=2;
    vector<T> tree(2*m);
    rep(i,0,n) {
        ll x = (100*inv[a[i]])%MOD;
        tree[m+i].prod_until = x;
        tree[m+i].expval = x;
        tree[m+i].expval_after = x;
    }
    for(int i=m-1;i>0;--i) {
        combine(tree[i],tree[2*i],tree[2*i+1]);
    }
    rep(i,0,q) {
        int j;
        cin >> j;
        --j;
        if(!tree[m+j].has) {
            tree[m+j].has = true;
            tree[m+j].prod_until = 1;
        }
        else {
            tree[m+j].has = false;
            tree[m+j].prod_until = tree[m+j].expval;
        }
        j=(m+j)/2;
        while(j>0) {
            combine(tree[j],tree[2*j],tree[2*j+1]);
            j/=2;
        }
        cout<<tree[1].expval<<"\n";
    }
}