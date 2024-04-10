#include <bits/stdc++.h>
using namespace std;

int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int x; string s;
    cin >> x >> s >> s;
    if (s == "week") {
        int ans = 51;
        if (x > 4) ans++;
        if (x < 7) ans++;
        cout << ans << '\n';
    } else {
        int cnt = 0;
        for (int y : days) if (y >= x) cnt++;
        cout << cnt << '\n';
    }
    return 0;
}