#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        int x = 0;
        for(int i = 1; i <= n; i++){
                int a, b;
                cin >> b;
                a = b + x;
                cout << a << " ";
                x = max(x, a);
        }
}