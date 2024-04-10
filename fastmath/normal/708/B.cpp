#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0 && d == 0) {
        if (b == 0 && c == 0) {
            cout << "0\n";
            exit(0);
        }
        else if (b > 1 || c > 1) {
            cout << "Impossible\n";
            exit(0);
        }   
        else if (b && c) {
            cout << "Impossible\n";
            exit(0);
        }
        else if (b) {
            cout << "01\n";
            exit(0);
        }
        else if (c) {
            cout << "10\n";
            exit(0);
        }
    }

    if (a == 0) {
        int t = 0;
        while (t * (t - 1) / 2 < d) ++t;

        if (t * (t - 1) / 2 != d) {
            cout << "Impossible\n";
            exit(0);
        }

        if (b + c) {
            if (b + c == t) {
                for (int i = 0; i < c; ++i) cout << '1';
                cout << '0';
                for (int i = 0; i < b; ++i) cout << '1';
                cout << '\n';
                exit(0);
            }
            else {
                cout << "Impossible\n";
                exit(0);
            }
        }   
        else {
            for (int i = 0; i < t; ++i) cout << '1';
            exit(0);
        }
    }

    if (d == 0) {
        int t = 0;
        while (t * (t - 1) / 2 < a) ++t;

        if (t * (t - 1) / 2 != a) {
            cout << "Impossible\n";
            exit(0);
        }

        if (b + c) {
            if (b + c == t) {
                for (int i = 0; i < b; ++i) cout << '0';
                cout << '1';
                for (int i = 0; i < c; ++i) cout << '0';
                cout << '\n';
                exit(0);
            }
            else {
                cout << "Impossible\n";
                exit(0);
            }
        }
        else {
            for (int i = 0; i < t; ++i) cout << '0';
            exit(0);
        }
    }

    int x = 0;
    while (x * (x - 1) / 2 < a) ++x;
    
    int y = 0;
    while (y * (y - 1) / 2 < d) ++y;

    if (x * (x - 1) / 2 != a) {
        cout << "Impossible\n";
        exit(0);
    }

    if (y * (y - 1) / 2 != d) {
        cout << "Impossible\n";
        exit(0);
    }

    if (x * y != b + c) {
        cout << "Impossible\n";
        exit(0);
    }
    
    int cnt = 0;
    int curr = c;
    int pos = -1;
    int post = y;
    for (int i = 0; i < y; ++i) {
        if (!curr) break;
        --post;
        if (x <= curr) {
            curr -= x;
            ++cnt;
        }   
        else {
            pos = x - curr;
            break;
        }
    }

    for (int i = 0; i < cnt; ++i) cout << '1';
    if (pos != -1) {
        for (int i = 0; i < pos; ++i) cout << '0';
        cout << '1';
        for (int i = 0; i < x - pos; ++i) cout << '0';
    }
    else {
        for (int i = 0; i < x; ++i) cout << '0';
    }
    for (int i = 0; i < post; ++i) cout << '1';
    cout << '\n';

    return 0;
}