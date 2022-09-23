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

int n, k;
int c[N];
int a[N];
int b[N];
bool d[N];

bool can(int m)
{
    for(int i = m; i >= 1; i--){
        b[i] = a[i];
        if(d[b[i]])
            b[i] = 0;
        else
            d[b[i]] = true;
    }
    vector < pair < int, int > > v;
    for(int i = 1; i <= m; i++){
        d[b[i]] = false;
        if(b[i]){
            v.pb({b[i], i});
        }
    }
    if(v.size() != k)
        return false;
    int cur = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].se - 1 - cur < c[v[i].fi])
            return false;
        cur += c[v[i].fi] + 1;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    for(int i = 1; i <= k; i++)
        sc("%d", &c[i]);
    int l = 1,
        r = n + 1;
    while(l < r){
        int m = (l + r) / 2;
        if(can(m))
            r = m;
        else
            l = m + 1;
    }
    if(l == n + 1)
        l = -1;
    pr("%d\n", l);
}