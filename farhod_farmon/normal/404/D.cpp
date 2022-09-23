#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int d[2][5], mod = 1e9 + 7;
string s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.size() - 1;
    d[1][0] = d[1][3] = 1;
    for(int i = 0; i <= n; i++){
        int x = (i + 1) % 2,
            y = (i + 0) % 2;
        d[y][0] = d[y][1] = d[y][2] = d[y][3] = d[y][4] = 0;
        if(s[i] == '0' || s[i] == '?')
            d[y][0] = (d[x][0] + d[x][1]) % mod;
        if(s[i] == '1' || s[i] == '?')
            d[y][1] = d[x][4],
            d[y][2] = (d[x][0] + d[x][1]) % mod;
        if(s[i] == '2' || s[i] == '?')
            d[y][3] = d[x][4];
        if(s[i] == '*' || s[i] == '?')
            d[y][4] = (d[x][2] + d[x][3]) % mod,
            d[y][4] = (d[x][4] + d[y][4]) % mod;
    }
    n %= 2;
    int ans = d[n][0];
    ans = (ans + d[n][1]) % mod;
    ans = (ans + d[n][4]) % mod;
    cout << ans << endl;
}