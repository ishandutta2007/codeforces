#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector <int> a, happy;

void create_happy(int _n) {
    if (_n > 10000) return;
    happy[_n] = 1;
    create_happy(_n * 10 + 4);
    create_happy(_n * 10 + 7);
}

struct fenwick_tree {
    fenwick_tree(int n) {
        t.resize(n);
    }
    vector <int> t;
    void upd(int i, int val) {
        while (i < n) {
            t[i] += val;
            i |= (i + 1);
        }
    }
    int get(int i) {
        int res = 0;
        while (i != -1) {
            res += t[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    a.resize(n), happy.resize(10001);
    fenwick_tree t(n);
    create_happy(0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if (happy[a[i]])
            t.upd(i, 1);
    while (m--) {
        string s;
        cin >> s;
        if (s == "count") {
            int L, R;
            cin >> L >> R;
            L--, R--;
            cout << t.get(R) - t.get(L - 1) << '\n';
        }
        else {
            int L, R, val;
            cin >> L >> R >> val;
            L--, R--;
            for (int i = L; i <= R; i++) {
                if (happy[a[i]] && !happy[a[i] + val])
                    t.upd(i, -1);
                if (!happy[a[i]] && happy[a[i] + val])
                    t.upd(i, 1);
                a[i] += val;
            }
        }
    }
    return 0;
}