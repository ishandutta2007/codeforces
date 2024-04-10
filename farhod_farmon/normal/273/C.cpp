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
const long long MX = 5050;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
queue < int > q;
vector < int > v[N];

bool bad(int x)
{
        int cnt = 0;
        for(int y: v[x])
        {
                if(a[y] == a[x])
                {
                        cnt++;
                }
        }
        return cnt > 1;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = 1; i <= n; i++)
        {
                if(bad(i))
                {
                        q.push(i);
                }
        }
        while(!q.empty())
        {
                int x = q.front();
                q.pop();
                if(bad(x) == false)
                {
                        continue;
                }
                a[x] = 1 - a[x];
                for(int y: v[x])
                {
                        if(bad(y))
                        {
                                q.push(y);
                        }
                }
        }
        for(int i = 1; i <= n; i++)
        {
                cout << a[i];
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}