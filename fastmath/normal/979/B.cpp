#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int get(string s, int k) {
    int n = s.size();
    for (int i = 0; i < 256; ++i) cnt[i] = 0;
    for (char c : s) ++cnt[(int)c];
    int mx = 0;
    for (int i = 0; i < 256; ++i) mx = max(mx, cnt[i]);
    
    if (n == 1) return 1;
    else if (mx == n && k == 1) return n - 1;
    else return min(n, mx + k);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int a = get(s1, n), b = get(s2, n), c = get(s3, n);

    if (a > b && a > c) cout << "Kuro\n";
    else if (b > a && b > c) cout << "Shiro\n";
    else if (c > a && c > b) cout << "Katie\n";
    else cout << "Draw\n";
    
    return 0;
}