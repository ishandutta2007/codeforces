#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int f[1010][4040], s[100100], ans[100100], all, r[1010];
int t[100100], x[100100], y[100100];
vector < int > v[100100];

int n, m, q, sz;

int upd(int x1, int x2, int l, int r1, int g, int y1)
{
    if(l == r1){
        f[x1][x2] %= 2;
        if(f[x1][x2] == y1)
            return f[x1][x2];
        all += y1 * 2 - 1;
        r[x1] += y1 * 2 - 1;
        f[x1][x2] = y1;
        return 1 - y1;
    }
    int m1 = (l + r1) / 2;
    f[x1][x2 * 2] = (f[x1][x2 * 2] + f[x1][x2]) % 2;
    f[x1][x2 * 2 + 1] = (f[x1][x2 * 2 + 1] + f[x1][x2]) % 2;
    f[x1][x2] = 0;
    if(g <= m1)
        upd(x1, x2 * 2, l, m1, g, y1);
    else
        upd(x1, x2 * 2 + 1, m1 + 1, r1, g, y1);
}

void dfs(int i)
{
    int gg;
    if(t[i] <= 2)
        gg = upd(x[i], 1, 1, m, y[i], t[i] == 1 ? 1 : 0);
    if(t[i] == 3){
        f[x[i]][1]++;
        all = all - r[x[i]] + m - r[x[i]];
        r[x[i]] = m - r[x[i]];
    }
    ans[i] = all;
    for(int j = 0; j < v[i].size(); j++)
        dfs(v[i][j]);
    if(t[i] <= 2)
        upd(x[i], 1, 1, m, y[i], gg);
    if(t[i] == 3){
        f[x[i]][1]++;
        all = all - r[x[i]] + m - r[x[i]];
        r[x[i]] = m - r[x[i]];
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int cur = 0;
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++){
        cin >> t[i];
        if(t[i] == 1 || t[i] == 2){
            cin >> x[i] >> y[i];
            v[cur].pb(i);
            cur = i;
        }
        else if(t[i] == 3){
            cin >> x[i];
            v[cur].pb(i);
            cur = i;
        }
        else{
            cin >> x[i];
            cur = s[x[i]];
        }
        s[i] = cur;
    }
    dfs(0);
    for(int i = 1; i <= q; i++){
        ans[i] = ans[s[i]];
        cout << ans[i] << endl;
    }
}