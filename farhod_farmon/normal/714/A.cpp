#include <bits/stdc++.h>

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

long long l1, l2, r1, r2, k;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    r1 = min(r1, r2);
    l1 = max(l1, l2);
    long long ans = max(ans, r1 - l1 + 1);
    if(l1 <= k && k <= r1)
        ans--;
    cout << ans << endl;
}