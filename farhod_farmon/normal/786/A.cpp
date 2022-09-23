#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 7070;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k[2];
int a[N][2];
int c[N][2];
int used[N][2];
vector < pair < int, int > > v;

void upd(int x, int y, int f)
{
        if(used[x][y])
        {
                return;
        }
        if(f == 2)
        {
                used[x][y] = 1;
                v.pb({x, y});
        }
        else if(f == 1)
        {
                c[x][y]++;
                if(c[x][y] == k[y])
                {
                        used[x][y] = 2;
                        v.pb({x, y});
                }
        }
}

void solve()
{
        cin >> n >> k[0];
        for(int i = 1; i <= k[0]; i++)
        {
                cin >> a[i][0];
        }
        cin >> k[1];
        for(int i = 1; i <= k[1]; i++)
        {
                cin >> a[i][1];
        }
        used[0][0] = used[0][1] = 2;
        v.pb({0, 0});
        v.pb({0, 1});
        for(int f = 0; f < v.size(); f++)
        {
                int x = v[f].fi, y = v[f].se;
                for(int i = 1; i <= k[1 - y]; i++)
                {
                        int l = a[i][1 - y];
                        upd((x - l + n) % n, 1 - y, used[x][y]);
                }
        }
        for(int j = 0; j < 2; j++)
        {
                for(int i = 1; i < n; i++)
                {
                        if(used[i][j] == 1)
                        {
                                cout << "Win ";
                        }
                        else if(used[i][j] == 2)
                        {
                                cout << "Lose ";
                        }
                        else
                        {
                                cout << "Loop ";
                        }
                }
                cout << "\n";
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