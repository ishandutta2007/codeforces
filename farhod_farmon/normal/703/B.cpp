#include <bits/stdc++.h>

#define lli long long int
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

lli ans, n, c[N], k, x, s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    c[0] = c[n];
    c[n + 1] = c[1];
    for(int i = 1; i <= n; i++){
        s += c[i];
        ans += c[i] * c[i - 1];
    }
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        ans += c[x] * (s - c[x + 1] - c[x - 1] - c[x]);
        s -= c[x];
        c[x] = 0;
        if(x == 1)
            c[n + 1] = 0;
        if(x == n)
            c[0] = 0;
    }
    cout << ans << endl;
}