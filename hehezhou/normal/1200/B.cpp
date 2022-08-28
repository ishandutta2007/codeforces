#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int h[100010];
int main() {
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        for(int i = 1; i < n; i++) {
            int nh = max(0, h[i + 1] - k);
            m += h[i] - nh;
            if(m < 0) {cout << "NO" << endl; goto loop;}
        }
        cout << "YES" << endl;
        loop:;
    }
}