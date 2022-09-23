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

const int N = 100100;

using namespace std;

lli n, s[N];
long double ans[N];
vector < lli > v[N];

void f(lli x)
{
    s[x] = 1;
    for(int i = 0; i < v[x].size(); i++){
        f(v[x][i]);
        s[x] += s[v[x][i]];
    }
}

void dfs(lli x)
{
    lli sum = 0;
    for(int i = 0; i < v[x].size(); i++)
        sum += s[v[x][i]];
    for(int i = 0; i < v[x].size(); i++){
        lli y = v[x][i];
        ans[y] = ans[x] + (sum - s[y]) / 2.0 + 1;
        dfs(y);
    }
}

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        lli x;
        cin >> x;
        v[x].pb(i);
    }
    ans[1] = 1.0;
    f(1);
    dfs(1);
    cout << fixed << setprecision(7);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}