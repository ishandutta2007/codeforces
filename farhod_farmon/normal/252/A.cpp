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

lli n, a[101], i, j, cnt, mx;

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++)
        for(j = i, cnt = a[i]; j <= n; j++, cnt ^= a[j])
            mx = max(mx, cnt);
    cout << mx << endl;
}