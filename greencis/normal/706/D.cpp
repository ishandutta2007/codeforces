#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int q, xx;
char z[2];
int go[2][18600600], cnt[18600600], cur = 1;

inline void check(int v) {
    if (!go[0][v]) go[0][v] = ++cur;
    if (!go[1][v]) go[1][v] = ++cur;
}

void add(int x) {
    int v = 1;
    for (int i = 30; i >= 0; --i) {
        ++cnt[v];
        int curb = (x >> i) & 1;
        check(v);
        v = go[curb][v];
    }
    ++cnt[v];
}

void del(int x) {
    int v = 1;
    for (int i = 30; i >= 0; --i) {
        --cnt[v];
        int curb = (x >> i) & 1;
        check(v);
        v = go[curb][v];
    }
    --cnt[v];
}

int query(int x) {
    int ans = 0;
    int v = 1;
    for (int i = 30; i >= 0; --i) {
        int curb = (x >> i) & 1;
        check(v);
        if (cnt[go[!curb][v]]) {
            v = go[!curb][v];
            ans ^= (1 << i);
        } else {
            v = go[curb][v];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> q;
    for (int i = 0; i < 200105; ++i) add(0);

    while (q--) {
        cin >> z >> xx;
        if (*z == '+') {
            add(xx);
        } else if (*z == '-') {
            del(xx);
        } else {
            cout << query(xx) << "\n";
        }
    }

    return 0;
}