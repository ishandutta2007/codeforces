#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

long long n;
long long k;
long long s[N];
pair < long long, long long > x[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i].fi;
        x[i].se = i;
    }
    cin >> k;
    sort(x + 1, x + n + 1);
    for(int i = 1; i <= n; i++)
        s[i] += s[i - 1] + x[i].fi;
    long long f = 0;
    for(int i = 1; i <= k; i++)
        f += 1ll * i * x[i].fi - s[i];
    long long ans = f,
              h = 1;
    for(int i = k + 1; i <= n; i++){
        long long xx = 1ll * k * x[i].fi - (s[i] - s[i - k]),
                  yy = (s[i - 1] - s[i - k - 1]) - 1ll * k * x[i - k].fi;
        f = f + xx - yy;
        if(f < ans){
            ans = f;
            h = i - k + 1;
        }
    }
    for(int i = h; i < h + k; i++)
        cout << x[i].se << " ";
}