#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 55;
const int MX = 10000001;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int d[N][1 << 5];
char c[N][N];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < (1 << 3); i++)
        d[0][i] = 1e9;
    for(int i = 1; i <= n; i++){
        int a1 = 1e9,
            a2 = 1e9,
            a3 = 1e9;
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if('0' <= c[i][j] && c[i][j] <= '9')
                a1 = min(a1, min(j - 1, 1 + m - j));
            else if('a' <= c[i][j] && c[i][j] <= 'z')
                a2 = min(a2, min(j - 1, 1 + m - j));
            else
                a3 = min(a3, min(j - 1, 1 + m - j));
        }
        for(int j = 0; j < (1 << 3); j++)
            d[i][j] = d[i - 1][j];
        d[i][1] = min(d[i][1], a1);
        d[i][2] = min(d[i][2], a2);
        d[i][4] = min(d[i][4], a3);
        for(int j = 0; j < (1 << 3); j++){
            for(int h = 0; h < 3; h++){
                if(!(j & (1 << h)))
                    d[i][j | (1 << h)] = min(d[i][j | (1 << h)], d[i - 1][j] + a1);
                swap(a1, a2);
                swap(a2, a3);
            }
        }
    }
    cout << d[n][7] << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}