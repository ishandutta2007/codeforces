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

const int N = 1111111;
int a[N];

const int mod = 1000000007;

long long pw(long long a, long long b){
    if (a > mod)
        a %= mod;
    long long res = 1;
    while (b){
        if (b & 1ll)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

long long inv(long long a){
    return pw(a, mod - 2);
}

struct Tree{
    int n;
    vector<long long> tree;
    vector<long long> add;

    Tree(int nn){
        n = 1;
        while (n < nn)
            n *= 2;
        tree.resize(n + n, 1);
        add.resize(n + n, 1);
    }

    void relax(int v){
        add[v + v] = add[v + v] * add[v] % mod;
        add[v + v + 1] = add[v + v + 1] * add[v] % mod;
        add[v] = 1;
    }

    void _mul(int v, int l1, int r1, int l, int r, int x){
        if (l >= r1 || l1 >= r)
            return;
        if (l < l1)
            l = l1;
        if (r > r1)
            r = r1;
        if (l == l1 && r == r1){
            add[v] = add[v] * x % mod;
            return;
        }
        tree[v] = tree[v] * pw(x, r - l) % mod;
        relax(v);
        int mid = (l1 + r1) / 2;
        _mul(v + v, l1, mid, l, r, x);
        _mul(v + v + 1, mid, r1, l, r, x);
    }

    void mul(int l, int r, int x){
        _mul(1, 0, n, l, r, x);
    }

    long long _get(int v, int l1, int r1, int l, int r){
        if (l >= r1 || l1 >= r)
            return 1;
        if (l < l1)
            l = l1;
        if (r > r1)
            r = r1;
        if (l == l1 && r == r1)
            return tree[v] * pw(add[v], r - l) % mod;
        int mid = (l1 + r1) / 2;
        return _get(v + v, l1, mid, l, r) * _get(v + v + 1, mid, r1, l, r) % mod * pw(add[v], r - l) % mod;
    }

    long long get(int l, int r){
        return _get(1, 0, n, l, r);
    }

    void show(int v = 1, int l = 0, int r = -1){
        if (r == -1)
            r = n;
        cerr << "[" << l << ", " << r << "): " << tree[v] << "\n";
        if (l + 1 < r){
            show(v + v, l, (l + r) / 2);
            show(v + v + 1, (l + r) / 2, r);
        }
    }
};

int main(){

    a[1] = 1;
    for (int i = 2; i < N; i++){
        if (a[i] == 0){
            a[i] = i;
            if (1.0 * i * i < N + N){
                for (int j = i * i; j < N; j += i){
                    if (a[j] == 0){
                        a[j] = i;
                    }
                }
            }
        }
    }

    vector<int> pr;
    for (int i = 2; i < N; i++)
        if (a[i] == i)
            pr.push_back(i);
    int sz = pr.size();
    vector<int> lst(sz, -1);

    int n = nxt();
    vector<int> ar(n);
    Tree tree(n);
    for (int i = 0; i < n; i++){
        ar[i] = nxt();
    }
    int q = nxt();
    vector<pair<pair<int, int>, int>> b(q);
    for (int i = 0; i < q; i++){
        b[i].first.second = nxt() - 1;
        b[i].first.first = nxt();
        b[i].second = i;
    }
    sort(all(b));
    vector<long long> s(n + 1);
    s[0] = 1;
    for (int i = 0; i < n; i++){
        s[i + 1] = s[i] * ar[i] % mod;
    }
    vector<long long> ans(q);
    int cur = 0;
    for (int i = 0; i < n && cur < q; i++){
        int x = ar[i];
        while (x > 1){
            int g = a[x];
            x /= g;
            int pos = lower_bound(all(pr), g) - pr.begin();
            tree.mul(lst[pos] + 1, i + 1, inv(g) * (g - 1) % mod);
            lst[pos] = i;
        }
        // tree.show();
        // cerr << "\n";
        while (cur < q && b[cur].first.first == i + 1){
            ans[b[cur].second] = tree.get(b[cur].first.second, b[cur].first.second + 1);
            cur++;
        }
    }
    for (int i = 0; i < q; i++)
        ans[b[i].second] = ans[b[i].second] * s[b[i].first.first] % mod * inv(s[b[i].first.second]) % mod;
    for (int i = 0; i < q; i++)
        printf("%I64d\n", ans[i]);

    return 0;
}