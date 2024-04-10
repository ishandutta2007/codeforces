//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;
 
int tst;
int win[205][205];
 
bool query(int i, int j) { // operator <
    cout << "? " << i << " " << j << endl;
    char z[2];
    cin >> z;
    return z[0] == '<';
}
 
struct Element {
    int pos;
 
    Element(int _pos) : pos(_pos) {
    }
 
    bool operator<(const Element& rhs) const {
        int a = pos;
        int b = rhs.pos;
        if (win[a][b] != tst * 2 - 1 && win[a][b] != tst * 2) {
            bool is_less = query(a, b);
            if (is_less)
                win[a][b] = tst * 2 - 1, win[b][a] = tst * 2;
            else
                win[a][b] = tst * 2, win[b][a] = tst * 2 - 1;
        }
        return win[a][b] == tst * 2 - 1;
    }
};
 
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
 
    int ttt;
    cin >> ttt;
    for (tst = 1; tst <= ttt; ++tst) {
        int n;
        cin >> n;
        set<Element> lhs, rhs;
        for (int i = 1; i <= n / 2; ++i)
            lhs.emplace(i);
        for (int i = n / 2 + 1; i <= n; ++i)
            rhs.emplace(i);
        for (int i = n + 1; i <= 2 * n; ++i) {
            (lhs.size() < rhs.size() ? lhs : rhs).emplace(i);
            if (*lhs.begin() < *rhs.begin())
                lhs.erase(lhs.begin());
            else
                rhs.erase(rhs.begin());
        }
        cout << "!" << endl;
    }
}