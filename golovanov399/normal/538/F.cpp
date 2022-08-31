#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int INF = 1e9;
vector<vector<int>> tree;
vector<int> ans;
vector<int> a;
int N, n;

int get(int v, int l, int r, int ll, int rr, int x){
    if (rr > r)
        rr = r;
    if (ll < l)
        ll = l;
    if (l == ll && r == rr){
        // cerr << v << " " << l << " " << r << " " << x << "\n";
        return upper_bound(all(tree[v]), x) - tree[v].begin();
    }
    if (rr <= l || r <= ll)
        return 0;
    int m = (l + r) / 2;
    return get(v + v, l, m, ll, rr, x) + get(v + v + 1, m, r, ll, rr, x);
}

void make(int v){
    if (v == 1){
        for (int k = 1; k <= n - 1; k++){
            ans[k] += min(k * v + 1, n) - k * (v - 1) - 1 - get(1, 0, N, k * (v - 1) + 1, min(k * v + 1, n), a[v - 1]);
        }
    } else {
        for (int k = 1; k <= (n - 2) / (v - 1); k++){
            ans[k] += min(k * v + 1, n) - k * (v - 1) - 1 - get(1, 0, N, k * (v - 1) + 1, min(k * v + 1, n), a[v - 1]);
        }
    }
}

int main(){

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }

    ans.resize(n);
    N = 1;
    while (N < n)
        N <<= 1;
    tree.resize(N + N);
    for (int i = 0; i < N; i++){
        if (i < n)
            tree[N + i].push_back(a[i]);
        else
            tree[N + i].push_back(INF);
    }
    for (int i = N - 1; i > 0; i--){
        auto x = tree[i + i].begin(), y = tree[i + i + 1].begin();
        while (x != tree[i + i].end() && y != tree[i + i + 1].end()){
            if ((*x) < (*y)){
                tree[i].push_back(*x);
                ++x;
            } else {
                tree[i].push_back(*y);
                ++y;
            }
        }
        while (x != tree[i + i].end()){
            tree[i].push_back(*x);
            ++x;
        }
        while (y != tree[i + i + 1].end()){
            tree[i].push_back(*y);
            ++y;
        }
    }

    for (int i = 1; i <= n; i++){
        make(i);
        // for (int j = 0; j < n; j++){
        //  cerr << ans[j] << " ";
        // }
        // cerr << "\n";
    }
    for (int i = 1; i < n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}