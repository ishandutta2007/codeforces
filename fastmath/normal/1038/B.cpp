#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int n) {
    int d = 2;
    while (d * d <= n) {
        if (n % d == 0) return d;
        ++d;
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    
    int d = get(sum);
    if (d == -1) {
        cout << "No\n";
    }  
    else {
        cout << "Yes\n";
        cout << "1 " << d << '\n';
        cout << n - 1 << ' ';
        for (int i = 1; i <= n; ++i) {
            if (i != d) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}