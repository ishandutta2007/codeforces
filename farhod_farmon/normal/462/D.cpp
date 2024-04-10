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

int d[N][2];
int n, a[N];
int mod = 1e9 + 7;
vector < int > v[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        v[p + 1].pb(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i >= 1; i--){
        d[i][0] = 1;
        for(auto y: v[i]){
            d[i][1] = (1ll * d[i][1] * d[y][0]) % mod;
            d[i][1] = (d[i][1] + (1ll * d[i][0] * d[y][1]) % mod) % mod;
            d[i][0] = (1ll * d[i][0] * d[y][0]) % mod;
        }
        if(a[i])
            d[i][1] = d[i][0];
        else
            d[i][0] = (d[i][0] + d[i][1]) % mod;
    }
    cout << d[1][1] << endl;
}