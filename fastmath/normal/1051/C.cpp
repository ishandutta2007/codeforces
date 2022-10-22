#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN], cnt[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) ++cnt[a[i]];

    vector <int> v;
    set <int> ms;
    for (int i = 0; i < MAXN; ++i) {
        if (cnt[i] == 1) {
            v.push_back(i);
            ms.insert(i);
        }
    }

    if ((int)v.size() % 2 == 0) {
        int c = 0;
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] == 2) {
                cout << 'A';
                continue;
            }

            if (ms.find(a[i]) == ms.end()) {
                cout << 'A';
            }
            else {
                if (c < (int)v.size() / 2) {
                    cout << 'A';
                    ++c;
                }
                else {
                    cout << 'B';
                }
            }
        }
        cout << '\n';
    }
    else {
        int x = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (2 < cnt[i]) {
                x = i;
                break;
            }
        }
        if (x == -1) {
            cout << "NO\n";
            exit(0);
        }
        cout << "YES\n";
        int c = 0;
        bool ch = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] == 2) {
                cout << 'A';
                continue;
            }

            if (a[i] == x) {
                if (!ch) {
                    cout << 'A';
                    ch = 1;
                }
                else {
                    cout << 'B';
                }
            }
            else if (ms.find(a[i]) == ms.end()) {
                cout << 'A';
            }
            else {
                if (c < (int)v.size() / 2) {
                    cout << 'A';
                    ++c;
                }
                else {
                    cout << 'B';
                }
            }
        }   
        cout << '\n';
    }

    return 0;
}