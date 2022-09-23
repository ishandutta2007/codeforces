#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 50050;

using namespace std;

long long n, m, t[N][6], ans[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> t[i][j];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)
            ans[j] = max(ans[j - 1], ans[j]) + t[j][i];
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}