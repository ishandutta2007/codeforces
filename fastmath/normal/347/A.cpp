#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

int n;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    sort(a, a + n);
    reverse(a, a + n);
    sort(a + 1, a + n - 1);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }   
    cout << '\n';

    return 0;
}