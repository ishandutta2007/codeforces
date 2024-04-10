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

int n;

int main()
{
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        ans += i * (x - 1) + x;
    }
    cout << ans << endl;
}