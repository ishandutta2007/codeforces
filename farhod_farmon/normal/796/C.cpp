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
int a[N];
int b[N];
vector < int > v[N];

int get(int x)
{
        int cnt = 0;
        for(int y: v[x])
        {
                if(b[y] == 1)
                {
                        cnt++;
                }
        }
        return cnt;
}

bool f(int k)
{
        int h = -1, d = 0;
        for(int i = 1; i <= n; i++)
        {
                b[i] = k - a[i];
                if(b[i] < 0)
                {
                        return false;
                }
                if(b[i] == 0)
                {
                        if(h == -1)
                        {
                                h = i;
                        }
                        else
                        {
                                return false;
                        }
                }
                if(b[i] == 1)
                {
                        d++;
                }
        }
        if(h != -1)
        {
                if(get(h) == d)
                {
                        return true;
                }
                return false;
        }
        for(int i = 1; i <= n; i++)
        {
                int x = get(i);
                if(b[i] == 1)
                {
                        x++;
                }
                if(x == d)
                {
                        return true;
                }
        }
        return false;
}

void solve()
{
        sc("%d", &n);
        int mx = -1e9 - 1;
        for(int i = 1; i <= n; i++)
        {
                sc("%d", &a[i]);
                mx = max(mx, a[i]);
        }
        for(int i = 1; i < n; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = mx - 10; i <= mx + 10; i++)
        {
                if(f(i))
                {
                        pr("%d\n", i);
                        return;
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