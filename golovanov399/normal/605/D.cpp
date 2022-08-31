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

struct Tree{
    int n;
    vector<vector<set<pair<int, int>>>> tree;

    Tree(int n):n(n){
        tree.resize(n);
        for (int i = 1; i <= n; i *= 2){
            for (int j = 0; j + i <= n; j += i){
                tree[j].emplace_back();
            }
        }
    }

    void add(int x, int y, int num){
        int i = x, j = 1, cur = 0;
        while (i >= 0 && i + j <= n){
            tree[i][cur].insert({y, num});
            if (i & j)
                i -= j;
            j *= 2;
            cur++;
        }
    }

    void remove(int x, int y, int num){
        int i = x, j = 1, cur = 0;
        while (i >= 0 && i + j <= n){
            tree[i][cur].erase({y, num});
            if (i & j)
                i -= j;
            j *= 2;
            cur++;
        }
    }

    vector<int> get(int x, int y){
        vector<int> res;
        int i = 0;
        int j = 1;
        int cur = 0;
        x += 1;
        while (j * 2 <= x){
            j *= 2;
            cur += 1;
        }
        // cerr << "x: " << x << "\n";
        while (j > 0){
            // cerr << "[" << i << ", " << i + j << ")\n";
            if (i + j <= x){
                for (set<pair<int, int>>::iterator it = tree[i][cur].begin(); it != tree[i][cur].end() && it->first <= y; ++it){
                    res.push_back(it->second);
                }
                i += j;
            }
            j /= 2;
            cur--;
        }
        return res;
    }
};

int main(){

    int n = nxt();
    vector<int> a(n), b(n), c(n), d(n);
    vector<int> ar;
    for (int i = 0; i < n; i++){
        a[i] = nxt();
        b[i] = nxt();
        c[i] = nxt();
        d[i] = nxt();
        ar.push_back(a[i]);
        ar.push_back(c[i]);
    }
    sort(all(ar));
    ar.resize(unique(all(ar)) - ar.begin());
    for (int i = 0; i < n; i++){
        a[i] = lower_bound(all(ar), a[i]) - ar.begin();
        c[i] = lower_bound(all(ar), c[i]) - ar.begin();
    }

    int sz = ar.size();
    Tree tree(sz);
    for (int i = 0; i < n; i++){
        tree.add(a[i], b[i], i);
    }

    queue<int> q;
    vector<int> ans(n, 1e9);
    vector<int> pr(n, -1);
    if (ar[0]){
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 0 && b[i] == 0){
            ans[i] = 1;
            q.push(i);
            tree.remove(a[i], b[i], i);
        }
    }

    while (!q.empty()){
        int v = q.front();
        q.pop();
        vector<int> qw = tree.get(c[v], d[v]);
        // cerr << v << ": ";
        for (auto w : qw){
            // cerr << w << " ";
            pr[w] = v;
            ans[w] = ans[v] + 1;
            tree.remove(a[w], b[w], w);
            q.push(w);
        }
        // cerr << "\n";
    }

    if (ans[n - 1] > 1e8){
        puts("-1");
        return 0;
    }

    vector<int> res;
    int cur = n - 1;
    while (cur >= 0){
        res.push_back(cur + 1);
        cur = pr[cur];
    }
    reverse(all(res));

    printf("%d\n", ans[n - 1]);
    for (auto x : res)
        printf("%d ", x);
    puts("");

    return 0;
}