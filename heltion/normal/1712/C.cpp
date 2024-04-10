#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        map<int, int> R;
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            R[a[i]] = i;
        }
        int s = n;
        while (s > 1 and a[s] >= a[s - 1])
            s -= 1;
        set<int> x;
        for (int i = 1; i < s; i += 1) {
            x.insert(a[i]);
            s = max(R[a[i]] + 1, s);
        }
        cout << x.size() << "\n";
    }
}