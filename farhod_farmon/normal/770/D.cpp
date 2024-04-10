#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 777;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int H;
char s[N];
char ans[N][N];

void F(int g, int h, int type)
{
        for(int i = h + 1; i <= 2 * H + 1 - h; i++)
        {
                ans[i][g] = '|';
        }
        ans[h][g] = ans[2 * H + 1 - h + 1][g] = '+';
        if(type)
        {
                ans[h][g - 1] = ans[2 * H + 1 - h + 1][g - 1] = '-';
        }
        else
        {
                ans[h][g + 1] = ans[2 * H + 1 - h + 1][g + 1] = '-';
        }
}

void solve()
{
        cin >> n;
        int h = 0;
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < N; j++)
                {
                        ans[i][j] = ' ';
                }
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> s[i];
                if(s[i] == '[')
                {
                        h++;
                }
                else
                {
                        h--;
                }
                H = max(H, h);
        }
        h = 0;
        int m = 0;
        for(int i = 1; i <= n; i++)
        {
                if(s[i] == '[')
                {
                        h++;
                        F(++m, h, 0);
                }
                else
                {
                        if(s[i - 1] == '[')
                        {
                                m += 3;
                        }
                        F(++m, h, 1);
                        h--;
                }
        }
        for(int i = 1; i <= 2 * H + 1; i++)
        {
                for(int j = 1; j <= m; j++)
                {
                        cout << ans[i][j];
                }
                cout << endl;
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