#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> q;
        while(q--){
                int a, b, c;
                cin >> a >> b >> c;
                int res = min(a, min(b, c));

                a -= res;
                b -= res;
                c -= res;

                res += min(min(a, b), (a + b) / 3);

                cout << res << "\n";
        }
}