#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int a[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    set <pair <int, int> > s1, s2;
    for (int i = 0; i < n; ++i) {
        s1.insert({a[i], i});
    }

    for (int i = 0; i < 2 * n; ++i) {
        char c;
        cin >> c;

        if (c == '0') {
            cout << s1.begin()->second + 1 << ' ';
            s2.insert({-s1.begin()->first, s1.begin()->second});
            s1.erase(s1.begin());
        }   
        else {
            cout << s2.begin()->second + 1 << ' ';
            s2.erase(s2.begin());
        }
    }
    cout << '\n';
    
    return 0;
}