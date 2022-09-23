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
int sz[N];
int p[N];
int a[N];
int b[N];
long long s[N];
long long ans[N];
set < pair < long long, long long > > all;

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

void mg(int x, int y)
{
    x = get(x);
    y = get(y);
    long long sm = s[x] + s[y];
    all.erase({-s[x], x});
    all.erase({-s[y], y});
    p[y] = x;
    s[x] = sm;
    all.insert({-s[x], x});
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        sc("%d", &b[i]);
    for(int i = n; i >= 1; i--){
        int x = b[i];
        s[x] = a[x];
        ans[i] = -(all.begin()->fi);
        all.insert({-s[x], x});
        sz[x] = 1;
        p[x] = x;
        if(sz[x - 1])
            mg(x, x - 1);
        if(sz[x + 1])
            mg(x, x + 1);
    }
    for(int i = 1; i <= n; i++)
        pr("%I64d\n", ans[i]);
}