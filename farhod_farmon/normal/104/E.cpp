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
const int magic = 547;

using namespace std;

long long n, m, w[N], ans[N], d[N];
vector < pair < int, int > > v[magic + 1];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    sc("%I64d", &n);
    for(int i = 1; i <= n; i++)
        sc("%I64d", &w[i]);
    sc("%I64d", &m);
    for(int i = 1; i <= m; i++){
        int a, b;
        sc("%d%d", &a, &b);
        if(b > magic)
            for(int j = a; j <= n; j += b)
                ans[i] += w[j];
        else
            v[b].pb({a, i});
    }
    for(int i = 1; i <= magic; i++){
        for(int j = 1; j <= n; j++)
            d[j] = w[j];
        for(int j = n; j > i; j--)
            d[j - i] += d[j];
        for(int j = 0; j < v[i].size(); j++)
            ans[v[i][j].se] = d[v[i][j].fi];
    }
    for(int i = 1; i <= m; i++)
        pr("%I64d\n", ans[i]);
}