#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(false);

        int t;
        cin >> t;
        while(t--){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int n = x2 - x1 + 1;
                int m = y2 - y1 + 1;
                cout << 1ll * (n - 1) * (m - 1) + 1 << "\n";
        }
}