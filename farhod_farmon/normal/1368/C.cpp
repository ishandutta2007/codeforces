#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        cout << 4 + 3 * n << "\n";

        cout << -1 << " " << 1 << "\n";
        cout << -1 << " " << 0 << "\n";
        cout << 0 << " " << 1 << "\n";
        cout << 0 << " " << 0 << "\n";

        int x = 0, y = 0;

        for(int i = 1; i <= n; i++){
                cout << x + 1 << " " << y << "\n";
                cout << x << " " << y - 1 << "\n";
                cout << x + 1 << " " << y - 1 << "\n";
                x += 1;
                y -= 1;
        }
}