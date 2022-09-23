#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 2020;
const int Q = N * N;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                int x, y, x1, y1, x2, y2;
                cin >> x >> y >> x1 >> y1 >> x2 >> y2;

                int res = 1;
                if(x1 == x2 && a + b > 0) res = 0;
                if(y1 == y2 && c + d > 0) res = 0;
                x += b - a;
                y += d - c;
                if(x < x1 || y < y1 || x > x2 || y > y2) res = 0;

                cout << (res ? "Yes" : "No") << "\n";
        }
}