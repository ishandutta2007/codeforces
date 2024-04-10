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

int n;
int d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        int x,
            f = 1;
        cin >> x;
        for(int j = 2; j * j <= x; j++){
            if(x % j)
                continue;
            f = max(f, d[j] + 1);
            f = max(f, d[x / j] + 1);
        }
        for(int j = 2; j * j <= x; j++){
            if(x % j)
                continue;
            d[j] = max(f, d[j]);
            d[x / j] = max(f, d[x / j]);
        }
        d[x] = f;
        ans = max(ans, f);
    }
    cout << ans << endl;
}