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
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int r[N];
int t[N];
int ans[N];
vector < int > q[N];

void upd(int x, int g)
{
        if(x == 0)
        {
                return;
        }
        while(x < N)
        {
                t[x] += g;
                x += x & -x;
        }
}

int get(int need)
{
        int x = 0;
        for(int i = 17; i >= 0; i--)
        {
                int l = (1 << i);
                if(x + l <= n && t[x + l] <= need)
                {
                        need -= t[x + l];
                        x += l;
                }
        }
        return x;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
        }
        for(int i = n; i >= 1; i--)
        {
                r[i] = b[a[i]];
                b[a[i]] = i;
        }
        for(int i = 1; i <= n; i++)
        {
                if(b[a[i]] == i)
                {
                        upd(i, 1);
                }
                q[1].pb(i);
        }
        for(int i = 1; i <= n; i++)
        {
                for(int x: q[i])
                {
                        int y = get(x);
                        ans[x]++;
                        q[y + 1].pb(x);
                }
                upd(r[i], 1);
                upd(i, -1);
        }
        for(int i = 1; i <= n; i++)
        {
                cout << ans[i] << " ";
        }
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