#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int x, y;
                cin >> x >> y;
                if(x > y){
                        swap(x, y);
                }
                cout << x * 2 + max(0, (y - x) * 2 - 1) << "\n";
        }
}