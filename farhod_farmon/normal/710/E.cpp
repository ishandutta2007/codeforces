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

using namespace std;

lli d[20000001];
lli n, x, y;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> x >> y;
    for(int i = 1; i <= n + n; i++)
        d[i] = 1e18;
    for(int i = 1; i <= n; i++){
        if(d[i] != 1e18)
            continue;
        d[i] = min(d[i - 1], d[i + 1]) + x;
        for(int j = i; j + j <= n + n; j += j)
            d[j + j] = min(d[j + j], d[j] + min(y, j * x));
    }
    cout << d[n] << endl;
}