#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct event {
    int x, bal, idx;
    bool operator<(const event& rhs) const {
        return x == rhs.x ? bal < rhs.bal : x < rhs.x;
    }
} e[200105];

int n, ans[100105], u[3];

int main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            e[i + i] = event{x, -1, i};
            e[i + i + 1] = event{y, 1, i};
        }
        sort(e, e + n + n);
        int clr = 2;
        int balance = 0;
        for (int i = 0; i < n + n; ++i) {
            if (balance == 0 && e[i].bal == -1)
                clr ^= 3;
            balance -= e[i].bal;
            if (e[i].bal == -1)
                ans[e[i].idx] = clr;
        }
        int check = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 1) ++check;
            else --check;
        }
        if (check == n || check == -n) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            cout << (i ? " " : "") << ans[i];
        cout << "\n";
    }
}