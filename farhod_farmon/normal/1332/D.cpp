#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 550;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int k;
        cin >> k;
        int b = (1 << 17), a = b | k;

        cout << 3 << " " << 3 << "\n";
        cout << a << " " << k << " " << 0 << "\n";
        cout << b << " " << a << " " << k << "\n";
        cout << 0 << " " << k << " " << k << "\n";
}