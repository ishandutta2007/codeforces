#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

set < pair < long long, long long > > s;
long long n, a[N], d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long mx = -1e18;
    for(int i = n - 1; i >= 1; i--){
        mx = max(mx, a[i + 1] - d[i + 1]);
        d[i] = mx;
    }
    cout << d[1] << endl;
}