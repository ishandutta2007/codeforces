#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
                                      
const int MAXN = 5e5 + 7;

int a[MAXN];
int tree[MAXN * 4];

inline int gcd(int a, int b){
    while (b){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void relax(int v){
    tree[v] = gcd(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void build(int v, int tl, int tr){
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    relax(v);
}

void upd(int v, int tl, int tr, int p, int x){
    if (tl == tr){
        tree[v] = x;
        return;
    }

    int tm = (tl + tr) / 2;
    if (p <= tm){
        upd(v * 2 + 1, tl, tm, p, x);
    }
    else{
        upd(v * 2 + 2, tm + 1, tr, p, x);
    }

    relax(v);
}

int get(int v, int tl, int tr, int l, int r){
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return gcd(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}

int getl(int v, int tl, int tr, int l, int r, int x){
    if (tr < l || r < tl) return -1;
    if (tree[v] % x == 0) return -1;
    
    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;
    int left = getl(v * 2 + 1, tl, tm, l, r, x);
    if (left != -1) return left;
    else return getl(v * 2 + 2, tm + 1, tr, l, r, x);
}

int getr(int v, int tl, int tr, int l, int r, int x){
    if (tr < l || r < tl) return -1;
    if (tree[v] % x == 0) return -1;

    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;
    int right = getr(v * 2 + 2, tm + 1, tr, l, r, x);
    if (right != -1) return right;
    else return getr(v * 2 + 1, tl, tm, l, r, x);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    build(0, 0, n - 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        int t;
        cin >> t;

        if (t == 1){
            int l, r, x;
            cin >> l >> r >> x;

            if (get(0, 0, n - 1, l - 1, r - 1) % x == 0){
                cout << "YES\n";
            }
            else{
                int left = getl(0, 0, n - 1, l - 1, r - 1, x);
                int right = getr(0, 0, n - 1, l - 1, r - 1, x);

                if (left == right){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
        else{
            int p, x;
            cin >> p >> x;
            upd(0, 0, n - 1, p - 1, x); 
        }
        
    }


    return 0;
}