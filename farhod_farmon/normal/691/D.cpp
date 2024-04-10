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

const int N = 1000011;

using namespace std;

int n, m, a[N], p[N];
vector < int > v[N];

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    //ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        sc("%d", &a[i]);
        p[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        sc("%d%d", &x, &y);
        x = get(x);
        y = get(y);
        if(x == y)
            continue;
        p[x] = y;
    }
    for(int i = 1; i <= n; i++)
        v[get(i)].pb(a[i]);
    for(int i = 1; i <= n; i++)
        if(v[i].size())
            sort(v[i].begin(), v[i].end());
    for(int i = 1; i <= n; i++){
        int x = get(i);
        pr("%d ", v[x].back());
        v[x].pop_back();
    }
}