#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000200;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
bool d[N];
bool used[N];

void solve()
{
        sc("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; i++)
        {
                int x;
                sc("%d", &x);
                used[x] = 1;
        }
        d[1] = 1;
        if(used[1])
        {
                pr("1");
                return;
        }
        for(int i = 1; i <= k; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                if(d[x])
                {
                        d[x] = 0;
                        d[y] = 1;
                        if(used[y])
                        {
                                pr("%d", y);
                                return;
                        }
                }
                else if(d[y])
                {
                        d[x] = 1;
                        d[y] = 0;
                        if(used[x])
                        {
                                pr("%d", x);
                                return;
                        }
                }
        }
        for(int i = 1; i <= n; i++)
        {
                if(d[i])
                {
                        pr("%d", i);
                }
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