#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 200200;
const long long MAGIC = 250;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int a[N];
int d[N];
int ans[N];
vector < pair < int, int > > v[MAGIC];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
        }
        cin >> q;
        for(int i = 1; i <= q; i++)
        {
                int p, k;
                cin >> p >> k;
                if(k >= MAGIC)
                {
                        int cnt = 0;
                        while(p <= n)
                        {
                                cnt++;
                                p = p + a[p] + k;
                        }
                        ans[i] = cnt;
                }
                else
                {
                        v[k].pb({i, p});
                }
        }
        for(int i = 1; i < MAGIC; i++)
        {
                for(int j = n; j >= 1; j--)
                {
                        if(j + a[j] + i > n)
                        {
                                d[j] = 1;
                        }
                        else
                        {
                                d[j] = d[j + a[j] + i] + 1;
                        }
                }
                for(auto p: v[i])
                {
                        ans[p.fi] = d[p.se];
                }
        }
        for(int i = 1; i <= q; i++)
        {
                cout << ans[i] << endl;
        }
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