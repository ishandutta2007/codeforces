#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 65010;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(false);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                n *= m;
                cout << (n + 1) / 2 << "\n";
        }
}