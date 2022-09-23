#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n, m;
int a[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);


        cin >> n >> m;
        long long all = 0;
        int last = 0;
        for(int i = 1; i <= m; i++){
                cin >> a[i];
                all += a[i];
                if(n - a[i] < i - 1){
                        cout << -1 << "\n";
                        return 0;
                }
                last = max(last, i + a[i] - 1);
        }
        if(all < n){
                cout << -1 << "\n";
                return 0;
        }
        int mx = 0;
        int rem = n - last, df = 0;
        for(int i = 1; i <= m; i++){
                // [i, mx + 1]
                int g = min(mx + 1, i + rem + df);
                rem -= g - i - df;
                df += g - i - df;
                cout << g << " ";
                mx = max(mx, g + a[i] - 1);
        }
}