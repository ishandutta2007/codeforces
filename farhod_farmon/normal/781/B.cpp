#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 50050;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];
int mt[N];
int mt2[N];
int ans[N];
int used[N];
string s[N];
string t[N];
bool us[N];

bool dfs(int x)
{
        if(x == 0)
                return true;
        if(us[x] || used[a[x]] > 1)
                return false;
        us[x] = true;
        if(dfs(mt[a[x]]))
        {
                mt[a[x]] = x;
                ans[x] = 1;
                return true;
        }
        else if(dfs(mt[b[x]]))
        {
                mt[b[x]] = x;
                ans[x] = 2;
                return true;
        }
        return false;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> s[i] >> t[i];
                for(int j = 0; j < 3; j++)
                        a[i] = a[i] * 27 + s[i][j] - 'A' + 1;
                for(int j = 0; j < 2; j++)
                        b[i] = b[i] * 27 + s[i][j] - 'A' + 1;
                b[i] = b[i] * 27 + t[i][0] - 'A' + 1;
                used[a[i]]++;
        }
        for(int i = 1; i <= n; i++)
        {
                if(used[a[i]] > 1)
                {
                        if(mt[b[i]])
                        {
                                cout << "NO" << endl;
                                return;
                        }
                        mt[b[i]] = i;
                        ans[i] = 2;
                }
        }
        for(int i = 1; i <= n; i++)
        {
                if(used[a[i]] == 1)
                {
                        if(dfs(i) == false)
                        {
                                cout << "NO" << endl;
                                return;
                        }
                }
                for(int j = 1; j <= n; j++)
                        us[j] = false;
        }
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++)
        {
                string f = "";
                for(int j = 0; j < 2; j++)
                        f += s[i][j];
                if(ans[i] == 1)
                        f += s[i][2];
                else
                        f += t[i][0];
                cout << f << endl;
        }
        return;
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