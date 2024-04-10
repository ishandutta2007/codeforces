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

int x[N], i, j, d, h, n;
lli cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> d;
    for(i = 1; i <= n; i++)
        cin >> x[i];
    for(i = j = 1; i <= n; i++){
        while(j < n && x[j + 1] - x[i] <= d)
            j++;
        h = j - i;
        //cout << i << " " << j << endl;
        cnt += 1ll * h * (h - 1) / 2;
    }
    cout << cnt << endl;
}