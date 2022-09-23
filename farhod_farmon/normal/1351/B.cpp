#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int a, b, x, y;
                cin >> a >> b >> x >> y;
                if(a + x == b && b == y || a + y == b && b == x || b + x == a && a == y || b + y == a && a == x){
                        cout << "Yes" << "\n";
                } else{
                        cout << "No" << "\n";
                }
        }
}