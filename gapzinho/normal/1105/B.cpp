#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1005;

int v[ms];

main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int level = 0;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != c) cur = 0;
            else cur++;
            if(cur == k) {
                level++;
                cur = 0;
            }
        }
        ans = max(ans, level);
    }
    cout << ans << endl;
}