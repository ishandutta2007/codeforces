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
long long v[N];
long long c[N];
long long d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= q; i++){
        long long a, b, ans = 0, x = 1, y = 2;
        cin >> a >> b;
        for(int j = 1; j <= n; j++)
            d[j] = -1e18;
        for(int j = 1; j <= n; j++){
            long long f = v[j] * b;
            if(c[j] == x)
                f = max(f, d[y] + v[j] * b);
            else
                f = max(f, d[x] + v[j] * b);
            f = max(f, d[c[j]] + v[j] * a);
            ans = max(ans, f);
            if(f < d[c[j]])
                continue;
            d[c[j]] = f;
            if(c[j] == x || c[j] == y){
                if(d[x] < d[y])
                    swap(x, y);
            }
            else{
                if(d[c[j]] > d[x]){
                    y = x;
                    x = c[j];
                }
                else if(d[c[j]] > d[y])
                    y = c[j];
            }
        }
        cout << ans << endl;
    }
}