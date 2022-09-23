#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10050;
const long long MX = 200200;
const long long MAGIC = 250;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int p[N];
ll s[N];
ll d[N];
pair < int, int > c[N];
ll in[N];
ll out[N];

void solve()
{
        sc("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
                sc("%d", &a[i]);
        }
        for(int i = 1; i <= m; i++)
        {
                sc("%d%d", &c[i].fi, &c[i].se);
        }
        sort(a + 1, a + n + 1);
        sort(c + 1, c + m + 1);
        for(int i = 1; i <= n + n + 1; i++)
        {
                d[i] = in[i] = out[i] = 1e16;
        }
        for(int i = 1; i <= m; i++)
        {
                c[i].se = min(c[i].se, n);
                for(int j = 1; j <= n; j++)
                {
                        s[j] = s[j - 1] + abs(a[j] - c[i].fi);
                }
                for(int j = 0; j < n; j++)
                {
                        if(d[j] == 1e16)
                        {
                                continue;
                        }
                        in[j + 1] = d[j] - s[j];
                                out[min(j + c[i].se, n)] = min(out[min(j + c[i].se, n)], d[j] - s[j]);
                }
                for(int j = 1; j <= n; j++)
                {
                        if(j % c[i].se != 1 && c[i].se != 1)
                        {
                                in[j] = min(in[j], in[j - 1]);
                        }
                        d[j] = min(d[j], in[j] + s[j]);
                }
                for(int j = n; j >= 1; j--)
                {
                        if(j % c[i].se != 0 && c[i].se != 1)
                        {
                                out[j] = min(out[j], out[j + 1]);
                        }
                        d[j] = min(d[j], out[j] + s[j]);
                }
                for(int j = 1; j <= n + 1; j++)
                {
                        in[j] = out[j] = 1e16;
                }
        }
        if(d[n] == 1e16)
        {
                d[n] = -1;
        }
        cout << d[n] << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}