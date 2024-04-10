#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
long long a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--){
                a[i] += a[i + 1];
        }
        long long res = a[1];
        sort(a + 2, a + n + 1);
        for(int i = 0; i < k - 1; i++){
                res += a[n - i];
        }
        cout << res << "\n";
}