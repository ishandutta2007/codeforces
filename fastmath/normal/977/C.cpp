#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map <int, int> ms;
    for (int i = 0; i < n; ++i) ++ms[a[i]];

    if (k == 0) {
        if (ms[1]) {
            cout << "-1\n";
        }
        else {
            cout << "1\n";
        }
        return 0;
    }

    int curr = 0;
    for (pair <int, int> elem : ms) {
        curr += elem.second;
        if (curr == k) {
            cout << elem.first << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}