#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 262144;
int tree[N + N];

int ans[N][20];
int cost[N][20];

#define set aklsdgnlahsdlfkj

void set(int v, int x){
    v += N;
    tree[v] = x;
    v >>= 1;
    while (v > 0){
        tree[v] = max(tree[v + v], tree[v + v + 1]);
        v >>= 1;
    }
}

int get(int v, int l1, int r1, int l, int r){
    if (l >= r)
        return 0;
    if (l < l1) l = l1;
    if (r > r1) r = r1;
    if (l == l1 && r == r1)
        return tree[v];
    if (l >= r1 || l1 >= r)
        return 0;
    int m = (l1 + r1) >> 1;
    return max(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
}

int main(){

    int n;
    cin >> n;
    vector<int> p(n), l(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> l[i];

    map<int, int> ind;
    for (int i = 0; i < n; i++){
        ind[p[i] + l[i]] = distance(p.begin(), upper_bound(all(p), p[i] + l[i]));
    }

    for (int i = n - 1; i >= 0; i--){
        int v = ind[p[i] + l[i]];
        // cerr << i + 1 << " " << v << "\n";
        set(i, max(p[i] + l[i], get(1, 0, N, i + 1, v)));
    }
    for (int i = 0; i < n; i++){
        ans[i][0] = tree[N + i];
        cost[i][0] = 0;
    }
    for (int _ = 1; _ < 20; _++){
        for (int i = 0; i < n; i++){
            int v = ans[i][_ - 1];
            // int k = distance(p.begin(), upper_bound(all(p), v));
            int k = ind[v];
            if (k >= n){
                ans[i][_] = ans[i][_ - 1];
                cost[i][_] = cost[i][_ - 1];
            } else {
                ans[i][_] = ans[k][_ - 1];
                cost[i][_] = cost[i][_ - 1] + cost[k][_ - 1] + (p[k] - v);
            }
        }
    }
    // for (itn i = 0; i < n; i++){
    //  for (int j = 0; j < 20; j++){
    //      ans[i][j] = ind[ans[i][j]];
    //  }
    // }
    int q;
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        int res = 0;
        int k = 0;
        while (ans[x][k] < p[y])
            k++;
        k--;
        while (k >= 0){
            if (ans[x][k] < p[y]){
                int yy = ind[ans[x][k]];
                res += cost[x][k] + p[yy] - ans[x][k];
                x = yy;
            }
            k--;
        }
        cout << res << "\n";
    }

    return 0;
}