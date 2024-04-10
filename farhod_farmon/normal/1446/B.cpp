#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int mod = 1e9 + 7;

using namespace std;

int n, m;
int d[N][N];
string s, t;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> s >> t;
        int res = 0;
        for(int i = n - 1; i >= 0; i--){
                for(int j = m - 1; j >= 0; j--){
                        d[i][j] = max(d[i][j], d[i + 1][j] - 1);
                        d[i][j] = max(d[i][j], d[i][j + 1] - 1);
                        d[i][j] = max(d[i][j], d[i + 1][j + 1] - 2);
                        if(s[i] == t[j]){
                                d[i][j] = max(d[i][j], d[i + 1][j + 1] + 2);
                        }
                        res = max(res, d[i][j]);
                }
        }
        cout << res << "\n";
}