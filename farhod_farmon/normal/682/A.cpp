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

lli cnt, n, m, i;

int main()
{
    //fin
    //fout
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        lli x = ((i - 1) / 5 + 1) * 5 - i;
        cnt += (m - x) / 5 + (x <= m && x > 0);
        //cout << i << " " << (m - x) / 5 + 1 << endl;
    }
    cout << cnt << endl;
}