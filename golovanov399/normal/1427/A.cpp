#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

void solve() {
    int n = nxt();
    vector<int> a(n);
    generate(all(a), nxt);
    sort(all(a));
    if (accumulate(all(a), 0) == 0) {
        cout << "NO\n";
        return;
    } else if (accumulate(all(a), 0) > 0) {
        reverse(all(a));
    }

    cout << "YES\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}