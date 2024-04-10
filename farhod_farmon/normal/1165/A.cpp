#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int x, y;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> n >> y >> x >> s;
        int res = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < y; i++){
                int g = s[i] - '0';
                res += g ^ (i == x);
        }
        cout << res << "\n";
}