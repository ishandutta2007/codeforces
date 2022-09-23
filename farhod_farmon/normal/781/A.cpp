#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 1e4 + 1;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
vector < int > v[N];

void dfs(int x, int p)
{
        int s1 = a[x],
            s2 = a[p],
            h = 1;
        for(int y: v[x])
        {
                if(y == p)
                        continue;
                while(h == s1 || h == s2)
                    h++;
                a[y] = h;
                k = max(k, h);
                h++;
                dfs(y, x);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        a[1] = 1;
        k = 1;
        dfs(1, 0);
        cout << k << endl;
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
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