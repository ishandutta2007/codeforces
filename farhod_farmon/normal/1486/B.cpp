#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > x(n), y(n);
                for(int i = 0; i < n; i++){
                        cin >> x[i] >> y[i];
                }
                sort(x.begin(), x.end());
                sort(y.begin(), y.end());
                int l = (n - 1) / 2, r = n / 2;
                cout << 1ll * (x[r] - x[l] + 1) * (y[r] - y[l] + 1) << "\n";
        }
}