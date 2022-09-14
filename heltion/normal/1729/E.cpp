#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL query(LL x, LL y) {
    cout << "? " << x << " " << y << endl;
    LL z;
    cin >> z;
    return z;
}
void answer(LL x) {
    cout << "! " << x << endl;
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL ans = LLONG_MAX;
    for (int i = 2; i; i += 1) {
        LL x = query(1, i);
        if (x == -1) answer(i - 1);
        LL y = query(i, 1);
        if (x != y) answer(x + y);
    }
}