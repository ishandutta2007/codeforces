#include <bits/stdc++.h>
using namespace std;
int a[2010][2010];
int n, k;
char s[2010][2010];
int ans;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i++) {
        int _min = n + 1, _max = 0;
        for(int j = 1; j <= n; j++) {
            if(s[i][j] == 'B') _min = min(_min, j), _max = max(_max, j);
        }
        if(_min > _max) ans++;
        else {
            if(_max - _min + 1 > k) continue;
            int x1 = max(1, i - k + 1), y1 = max(_max - k + 1, 1), x2 = i, y2 = _min;
            a[x1][y1] += 1, a[x2 + 1][y2 + 1] += 1, a[x1][y2 + 1] -= 1, a[x2 + 1][y1] -= 1;
            // cerr << i << ' '  << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            // cerr << _min << ' ' << _max << endl;
        }
    }
    for(int i = 1; i <= n; i++) {
        int _min = n + 1, _max = 0;
        for(int j = 1; j <= n; j++) {
            if(s[j][i] == 'B') _min = min(_min, j), _max = max(_max, j);
        }
        if(_min > _max) ans++;
        else {
            if(_max - _min + 1 > k) continue;
            int x1 = max(1, _max - k + 1), y1 = max(i - k + 1, 1), x2 = _min, y2 = i;
            a[x1][y1] += 1, a[x2 + 1][y2 + 1] += 1, a[x1][y2 + 1] -= 1, a[x2 + 1][y1] -= 1;
            // cerr << i << ' '  << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            // cerr << _min << ' ' << _max << endl;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) a[i][j] += a[i][j - 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) a[i][j] += a[i - 1][j];
    int lala = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) lala = max(lala, a[i][j]);
    return cout << lala + ans << endl, 0;
}