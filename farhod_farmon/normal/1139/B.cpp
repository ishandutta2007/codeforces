#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
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
        for(int i = n; i >= 1; i--){
                if(i < n){
                        a[i] = min(a[i], a[i + 1] - 1);
                        a[i] = max(a[i], 0);
                }
                res += a[i];
        }
        cout << res << "\n";
}