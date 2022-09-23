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
int d[N][3][2];
int p[N][3][2];
int f[N];
bool used[N];
string s;

void solve()
{
        cin >> s;
        bool none = false;
        f[0] = s[0] % 3;
        for(int i = 1; i < s.size(); i++)
        {
                f[i] = (f[i - 1] + s[i]) % 3;
        }
        for(int i = 0; i < N; i++)
        {
                used[i] = true;
                for(int j = 0; j < 3; j++)
                {
                        d[i][j][0] = d[i][j][1] = 1e9;
                }
        }
        n = s.size();
        d[0][0][0] = 1;
        d[0][s[0] % 3][1] = 0;
        for(int i = 1; i < n; i++)
        {
                if(s[i] == '0')
                {
                        none = true;
                }
                int x = s[i] % 3;
                for(int j = 0; j < 3; j++)
                {
                        d[i][j][0] = d[i - 1][j][0] + 1;
                        d[i][j][1] = d[i - 1][j][1] + 1;
                        p[i][j][0] = i;
                        p[i][j][1] = i;
                }
                for(int j = 0; j < 3; j++)
                {
                        int h = ((j - x) % 3 + 3) % 3;
                        if(s[i] != '0')
                        {
                                if(d[i - 1][h][0] < d[i][j][1])
                                {
                                        d[i][j][1] = d[i - 1][h][0];
                                        p[i][j][1] = p[i - 1][h][0];
                                }
                        }
                        if(d[i - 1][h][1] < d[i][j][1])
                        {
                                d[i][j][1] = d[i - 1][h][1];
                                p[i][j][1] = p[i - 1][h][1];
                        }
                }
        }
        string ans = "";
        if(d[n - 1][0][1] == 1e9)
        {
                cout << none - 1 << endl;
                return;
        }
        int h = p[n - 1][0][1];
        int x = 0;
        int fr = n - 1;
        for(int i = d[n - 1][0][1] - 1; i >= 0; i--)
        {
                used[h] = false;
                x = ((x - (f[fr] - f[h])) % 3 + 3) % 3;
                fr = h - 1;
                h = p[h - 1][x][1];
                if(i == fr + 1)
                {
                        while(i)
                        {
                                used[i - 1] = false;
                                i--;
                        }
                }
        }
        for(int i = 0; i < n; i++)
        {
                if(used[i])
                {
                        cout << s[i];
                }
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