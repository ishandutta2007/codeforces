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

        int n, m;
        cin >> n >> m;
        vector < string > a(n), b(m);
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        for(int j = 0; j < m; j++){
                cin >> b[j];
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
                int x;
                cin >> x;
                x -= 1;
                cout << a[x % n] << b[x % m] << "\n";
        }
}