#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2010;
const long long MX = 5050;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int f[3] = {1, -1, 0};
int16_t p[N][N];
bool d[N][N];
string s;

bool can(int i, int j)
{
        if(s[i] == '?')
        {
                return true;
        }
        if(s[i] == 'W' && j != 0)
        {
                return false;
        }
        if(s[i] == 'L' && j != 1)
        {
                return false;
        }
        if(s[i] == 'D' && j != 2)
        {
                return false;
        }
        return true;
}

void solve()
{
        cin >> n >> k >> s;
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < N; j++)
                {
                        d[i][j] = 0;
                }
        }
        d[0][1000] = 1;
        for(int i = 0; i < n; i++)
        {
                for(int h = 0; h < 3; h++)
                {
                        if(can(i, h) == false)
                        {
                                continue;
                        }
                        for(int j = -k + 1; j < k; j++)
                        {
                                if(d[i][j + 1000] == 0)
                                {
                                        continue;
                                }
                                int nj = j + f[h];
                                d[i + 1][nj + 1000] = 1;
                                p[i + 1][nj + 1000] = h;
                        }
                }
        }
        if(d[n][k + 1000] == 0 && d[n][-k + 1000] == 0)
        {
                cout << "NO" << endl;
                return;
        }
        if(d[n][k + 1000] == 0)
        {
                k = -k;
        }
        for(int i = n; i > 0; i--)
        {
                if(p[i][k + 1000] == 0)
                {
                        s[i - 1] = 'W';
                }
                else if(p[i][k + 1000] == 1)
                {
                        s[i - 1] = 'L';
                }
                else
                {
                        s[i - 1] = 'D';
                }
                k -= f[p[i][k + 1000]];
        }
        cout << s << endl;
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