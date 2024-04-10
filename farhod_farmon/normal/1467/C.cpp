#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 110119;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n[3];
        cin >> n[0] >> n[1] >> n[2];
        vector < vector < int > > a(3);
        vector < long long > s(3, 0);
        vector < int > mn(3, 1e9);
        for(int i = 0; i < 3; i++){
                a[i].resize(n[i]);
                for(int j = 0; j < n[i]; j++){
                        cin >> a[i][j];
                        s[i] += a[i][j];
                        mn[i] = min(mn[i], a[i][j]);
                }
        }
        long long res = -1e18;

        res = max(res, s[0] + s[1] - s[2]);
        res = max(res, s[0] - s[1] + s[2]);
        res = max(res, - s[0] + s[1] + s[2]);

        for(int i = 0; i < 3; i++){
                for(int j = i + 1; j < 3; j++){
                        res = max(res, s[0] + s[1] + s[2] - 2ll * (mn[i] + mn[j]));
                }
        }

        cout << res << "\n";
}