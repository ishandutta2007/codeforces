#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
string s[N];
string t[N];

string f(string x)
{
        string y = "";
        for(int i = 1; i < x.size(); i++)
        {
                y += x[i];
        }
        y += x[0];
        return y;
}

int get()
{
        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
                int cnt = 0;
                t[i] = s[i];
                while(cnt < 52 && t[i] != s[1])
                {
                        t[i] = f(t[i]);
                        cnt++;
                }
                if(cnt == 52)
                {
                        return 1e9;
                }
                ans += cnt;
        }
        return ans;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> s[i];
        }
        int ans = 1e9;
        for(int i = 0; i < s[1].size(); i++)
        {
                ans = min(ans, get() + i);
                s[1] = f(s[1]);
        }
        if(ans == 1e9)
        {
                ans = -1;
        }
        cout << ans << endl;
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