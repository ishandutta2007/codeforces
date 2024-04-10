#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int l[2][N];
int r[2][N];
pair < int, int > p[2][N];

int f(int i, int j)
{
        return max(0, max(l[0][i], l[1][j]) - min(r[0][i], r[1][j]));
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> l[0][i] >> r[0][i];
                p[0][i] = {l[0][i], r[0][i]};
        }
        cin >> m;
        for(int i = 1; i <= m; i++)
        {
                cin >> l[1][i] >> r[1][i];
                p[1][i] = {l[1][i], r[1][i]};
        }
        int ans = 0;
        sort(p[0] + 1, p[0] + n + 1);
        sort(p[1] + 1, p[1] + m + 1);
        for(int i = 1; i <= n; i++)
        {
                l[0][i] = p[0][i].fi;
                r[0][i] = p[0][i].se;
        }
        for(int i = 1; i <= m; i++)
        {
                l[1][i] = p[1][i].fi;
                r[1][i] = p[1][i].se;
                swap(p[1][i].fi, p[1][i].se);
        }
        sort(p[1] + 1, p[1] + m + 1);
        for(int i = 1; i <= n; i++)
        {
                ans = max(ans, f(i, 1));
                ans = max(ans, f(i, m));
        }
        for(int i = 1; i <= m; i++)
        {
                ans = max(ans, f(1, i));
                ans = max(ans, f(n, i));
        }
        for(int i = 1; i <= m; i++)
        {
                l[1][i] = p[1][i].se;
                r[1][i] = p[1][i].fi;
        }
        for(int i = 1; i <= n; i++)
        {
                ans = max(ans, f(i, 1));
                ans = max(ans, f(i, m));
        }
        for(int i = 1; i <= m; i++)
        {
                ans = max(ans, f(1, i));
                ans = max(ans, f(n, i));
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}