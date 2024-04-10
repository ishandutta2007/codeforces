#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

inline int reflect(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 5;
    if (x == 3) return -1;
    if (x == 4) return -1;

    if (x == 5) return 2;
    if (x == 6) return -1;
    if (x == 7) return -1;
    if (x == 8) return 8;
    if (x == 9) return -1;

    return -1;
}

bool is_valid(int h, int m, int curh, int curm) {
    int d1 = reflect(curh / 10);
    int d2 = reflect(curh % 10);
    int d3 = reflect(curm / 10);
    int d4 = reflect(curm % 10);
    if (d1 == -1 || d2 == -1 || d3 == -1 || d4 == -1)
        return false;
    curh = d4 * 10 + d3;
    curm = d2 * 10 + d1;
    return curh < h && curm < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int h, m;
        int curh, curm;
        char z;
        cin >> h >> m >> curh >> z >> curm;
        while (!is_valid(h, m, curh, curm)) {
            ++curm;
            if (curm == m) {
                curm = 0;
                ++curh %= h;
            }
        }
        cout << curh / 10 << curh % 10 << ":" << curm / 10 << curm % 10 << endl;
    }
}