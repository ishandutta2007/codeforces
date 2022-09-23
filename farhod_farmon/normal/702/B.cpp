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

const int N = 500500;

using namespace std;

map < lli, lli > used;
lli n, x;
lli ans;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(lli i = 1; i <= n; i++){
        cin >> x;
        for(lli j = 0; (1ll << j) <= 2e9; j++)
            if((1ll << j) > x)
                ans += used[(1ll << j) - x];
        used[x]++;
    }
    cout << ans << endl;
}