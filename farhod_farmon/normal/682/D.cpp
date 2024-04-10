#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, m, k, d[12][1011][1011], l[1011][1011];
string s, t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    cin >> s >> t;
    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
            if(s[i] == t[j])
                l[i][j] = l[i + 1][j + 1] + 1;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int h = 0; h <= m; h++){
                if(j)
                    d[i][j][h] = max(d[i][j][h], d[i][j - 1][h]);
                if(h)
                    d[i][j][h] = max(d[i][j][h], d[i][j][h - 1]);
                if(i && j && h)
                    d[i][j][h] = max(d[i][j][h], d[i - 1][j][h]);
                if(!l[j][h] || d[i][j][h] < i)
                    continue;
                d[i + 1][j + l[j][h]][h + l[j][h]] = max(d[i + 1][j + l[j][h]][h + l[j][h]], d[i][j][h] + l[j][h]);
            }
        }
    }
    cout << d[k][n][m] << endl;
}