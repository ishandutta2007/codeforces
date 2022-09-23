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

vector < long long > v[N], g[N];
long long n, p;
long long ans;
long long a[N];
long long d[N];

void dfs(long long x, long long pr, long long k)
{
    d[x] = k;
    for(long long i = 0; i < v[x].size(); i++){
        if(v[x][i] == pr)
            continue;
        dfs(v[x][i], x, k - 1);
    }
}

bool cmp(int x, int y)
{
    return x > y;
}

bool can(long long x)
{
    if(x <= 1)
        return true;
    long long s = 0;
    for(int i = 2; i < 1 + x; i++)
        s += d[i];
    for(int j = 2, i = x + 1; i <= n; i++, j++){
        s += d[i];
        if(s - x * d[i] <= p)
            return true;
        s -= d[j];
    }
    return false;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    long long k;
    cin >> n >> k >> p;
    for(long long i = 1; i < n; i++){
        long long x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, 0, n);
    sort(d + 1, d + n + 1, cmp);
    long long l = 0,
              r = min(n - 1, k);
    while(l < r){
        long long m = (l + r) / 2;
        if(can(m + 1))
            l = m + 1;
        else
            r = m;
    }
    cout << l << endl;
}