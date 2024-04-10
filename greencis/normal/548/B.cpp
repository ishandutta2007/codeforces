#include <iostream>
#include <fstream>
using namespace std;

int n,m,q;
int a[505][505];
int c[505];

int cnt(int r) {
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        if (a[r][i]) ++cur;
        else cur = 0;
        ans = max(ans,cur);
    }
    return ans;
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        c[i] = cnt(i);
    while (q--) {
        int x,y;
        cin >> x >> y;
        a[x-1][y-1] ^= 1;
        c[x-1] = cnt(x-1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, c[i]);
        cout << ans << "\n";
    }
    return 0;
}