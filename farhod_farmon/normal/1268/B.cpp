#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;

        long long res = 0;
        int d[2] = {0, 0};
        for(int i = 1; i <= n; i++){
                cin >> a[i];

                res += a[i] / 2;
                d[i % 2] += a[i] % 2;
        }

        cout << res + min(d[0], d[1]) << "\n";
}