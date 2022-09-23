#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int c[1 << 20][2];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long res = 0;
        c[0][0] = 1;
        int s = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s ^= x;
                res += c[s][i % 2];
                c[s][i % 2] += 1;
        }
        cout << res << "\n";
}