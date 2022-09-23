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

lli n, k, a[101], mod = 1e9 + 7;

vector < vector < lli > > mul(vector < vector < lli > > x, vector < vector < lli > > y)
{
    vector < vector < lli > > v;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++){
        v[i].resize(n + 1);
        for(int j = 1; j <= n; j++){
            v[i][j] = 0;
            for(int h = 1; h <= n; h++)
                v[i][j] = (v[i][j] + (x[i][h] * y[h][j]) % mod) % mod;
        }
    }
    return v;
}

vector < vector < lli > > pw(vector < vector < lli > >  x, lli g)
{
    if(g == 1)
        return x;
    if(g % 2)
        return mul(x, pw(x, g - 1));
    else
        return pw(mul(x, x), g / 2);
}

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(lli i = 1; i <= n; i++)
        cin >> a[i];
    vector < vector < lli > > v;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++){
        v[i].resize(n + 1);
        for(int j = 1; j <= n; j++){
            lli x = a[i] ^ a[j];
            lli cnt = 0;
            for(lli h = 0; h < 60; h++)
                if(x & (1ll << h))
                    cnt++;
            if(cnt % 3 == 0)
                v[i][j] = 1;
            else
                v[i][j] = 0;
        }
    }
    if(k == 1){
        cout << n << endl;
        return 0;
    }
    v = pw(v, k - 1);
    lli ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans = (ans + v[i][j]) % mod;
    cout << ans << endl;
}