#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > c(26, 0);
        for(int i = 0; i < n; i++){
                string s;
                cin >> s;
                c[s[0] - 'a'] += 1;
        }
        int res = 0;
        for(int x: c){
                int a = x / 2, b = x - a;
                res += a * (a - 1) / 2;
                res += b * (b - 1) / 2;
        }
        cout << res << "\n";
}