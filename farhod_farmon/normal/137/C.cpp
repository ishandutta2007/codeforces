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
pair < int, int > p[N];

int main()
{
    sc("%d", &n);
    for(int i = 1; i <= n; i++)
        sc("%d%d", &p[i].fi, &p[i].se);
    sort(p + 1, p + n + 1);
    int mn = 0,
        cnt = 0;
    for(int i = 1; i <= n; i++){
        mn = max(mn, p[i].se);
        if(p[i].se < mn)
            cnt++;
    }
    pr("%d\n", cnt);
}