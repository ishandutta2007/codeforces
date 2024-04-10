#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 18;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                long long res = abs(x1 - x2);
                res += abs(y1 - y2);
                if(x1 != x2 && y1 != y2){
                        res += 2;
                }
                cout << res << "\n";
        }
}