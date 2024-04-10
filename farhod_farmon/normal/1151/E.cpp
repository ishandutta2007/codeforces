#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(a[i] > a[i - 1]){
                        res += 1ll * (a[i] - a[i - 1]) * (n - a[i] + 1);
                } else{
                        res += 1ll * (a[i - 1] - a[i]) * (a[i]);
                }
        }

        cout << res << "\n";
}