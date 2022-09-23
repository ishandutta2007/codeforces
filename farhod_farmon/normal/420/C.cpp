#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int p;
int d[N];
int c[N];
int f[N];
bool used[N];
map < pair < int, int >, int > us;
vector < int > v[N];

void solve()
{
        sc("%d%d", &n, &p);
        for(int i = 1; i <= n; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                if(us.find({x, y}) == us.end())
                {
                        v[x].pb(y);
                        v[y].pb(x);
                }
                d[x]++;
                d[y]++;
                us[{x, y}]++;
                us[{y, x}]++;
        }
        for(int i = 1; i <= n; i++)
        {
                c[d[i]]++;
        }
        f[0] = c[0];
        for(int i = 1; i <= n; i++)
        {
                f[i] = c[i];
                c[i] += c[i - 1];
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
                ans += c[n] - c[max(0, p - d[i])] + f[max(0, p - d[i])] - (d[i] + d[i] >= p);
                for(int y: v[i])
                {
                        if(d[i] + d[y] >= p && d[i] + d[y] - us[{i, y}] < p)
                        {
                                ans--;
                        }
                }
        }
        cout << ans / 2 << endl;
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