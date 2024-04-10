#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

long long n, m;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> m;
    long long ans = 0;
    for(long long h = 1; h <= 4000; h++){
        for(long long h2 = 1; h2 <= 4000; h2++){
            long long x = max(0ll, n - h - h + 1),
                      y = max(0ll, m - h2 - h2 + 1);
            ans += x * y;
        }
    }
    cout << ans << endl;
}