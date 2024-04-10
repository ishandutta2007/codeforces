#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2222;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int d[N + N];
bool used[N + N];
vector < int > v;

void solve()
{
        sc("%d%d", &n, &k);
        for(int i = 1; i <= k; i++)
        {
                int x;
                sc("%d", &x);
                x = n - x;
                if(used[x + N] == false)
                {
                        used[x + N] = true;
                        v.pb(x);
                }
        }
        queue < int > q;
        for(int i = 0; i < N + N; i++)
        {
                d[i] = 1e9;
        }
        for(int x: v)
        {
                d[x + N] = 1;
                q.push(x);
        }
        while(!q.empty())
        {
                int x = q.front();
                q.pop();
                for(int y: v)
                {
                        if(x + y + N < 0 || x + y + N >= N + N)
                        {
                                continue;
                        }
                        if(d[x + N] + 1 < d[x + y + N])
                        {
                                d[x + y + N] = d[x + N] + 1;
                                q.push(x + y);
                        }
                }
        }
        int ans = d[N];
        if(ans == 1e9)
        {
                ans = -1;
        }
        pr("%d\n", ans);
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