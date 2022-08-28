#include <bits/stdc++.h>
using namespace std;
int tag[245][110];
char s[110];
int n, a[110], b[110];
int main() {
    cin >> n >> s;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        ans += tag[0][i] = s[i - 1] - '0';
    }
    for(int i = 1; i < 240; i++) {
        int tmp = 0;
        for(int j = 1; j <= n; j++) {
            tag[i][j] = tag[i - 1][j];
            if(i % a[j] == b[j] % a[j] && i >= b[j]) tag[i][j] ^= 1;
            tmp += tag[i][j];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}