#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string ss;
        int x, ans = 0;
        cin >> ss >> x;
        int s = stoi(ss.substr(0, 2)) * 60 + stoi(ss.substr(3));
        set<int> si;
        for (int i = s; not si.contains(i); i = (i + x) % 1440) {
            si.insert(i);
            int h = i / 60, m = i % 60;
            if (h / 10 == m % 10 and h % 10 == m / 10)
                ans += 1;
        }
        cout << ans << "\n";
    }
}