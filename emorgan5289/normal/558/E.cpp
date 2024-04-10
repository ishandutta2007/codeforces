#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() { return s; }

    // insert x into the set with multiplicity k
    void insert(int x, int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s++;
    }

    // remove x from the set with multiplicity k
    void remove(int x, int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s--;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    int count(int x) {
        return index(x+1)-index(x);
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

fenwick_multiset<100005> f[26];
int cnt[26], n, q;

void p() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++) {
            int k = f[j].index(i+1);
            if (k > 0 && f[j].get(k-1)+f[j].count(f[j].get(k-1)) > i) {
                cout << char('a'+j);
            }
        }
    cout << endl;
}

void split(int i) {
    for (int c = 0; c < 26; c++) {
        int j = f[c].index(i);
        if (j > 0) {
            int k = f[c].get(j-1);
            int l = f[c].count(k);
            if (k+l-1 >= i) {
                int s = k+l-i;
                f[c].remove(k, s);
                f[c].insert(i, s);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        int c = s[i]-'a';
        if (f[c].size() == 0)
            f[c].insert(i);
        else {
            int j = f[c].get(f[c].size()-1);
            if (j+f[c].count(j) < i)
                f[c].insert(i);
            else
                f[c].insert(j);
        }
    }
    while (q--) {
        int l, r, k; cin >> l >> r >> k; l--, r--;
        split(l); split(r+1);
        for (int c = 0; c < 26; c++) {
            int i = f[c].index(l);
            cnt[c] = 0;
            while (f[c].get(i) <= r) {
                int j = f[c].get(i);
                int x = f[c].count(j);
                f[c].remove(j, x);
                cnt[c] += x;
            }
        }
        if (k == 1)
            for (int c = 0; c < 26; c++) {
                f[c].insert(l, cnt[c]);
                l += cnt[c];
            }
        else
            for (int c = 25; c >= 0; c--) {
                f[c].insert(l, cnt[c]);
                l += cnt[c];
            }
    }
    p();
}