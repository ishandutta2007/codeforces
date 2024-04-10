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

const int N = 100100;

using namespace std;

lli n, a[N], i, cnt;
map < lli, lli > m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++){
        a[i] += a[i - 1];    
        cnt = max(cnt, ++m[a[i]]);
    }
    cout << n - cnt << endl;
}