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
const long long MX = 5050;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int k;
vector < int > g;
vector < string > v;

bool can(int w)
{
        if(g[0] > w)
        {
                return false;
        }
        int cnt = 1, l = g[0];
        for(int i = 1; i < g.size(); i++)
        {
                if(g[i] > w)
                {
                        return false;
                }
                if(l + g[i] <= w)
                {
                        l += g[i];
                }
                else
                {
                        l = g[i];
                        cnt++;
                }
        }
        return cnt <= k;
}

void solve()
{
        cin >> k;
        string s;
        while(cin >> s)
        {
                v.pb(s);
        }
        for(int i = 0; i < v.size(); i++)
        {
                string s = v[i];
                int l = 0;
                for(int j = 0; j < s.size(); j++)
                {
                        l = 0;
                        while(j < s.size() && s[j] != '-')
                        {
                                l++;
                                j++;
                        }
                        if(j == s.size() && i + 1 < v.size())
                        {
                                l++;
                        }
                        else if(j < s.size() && s[j] == '-')
                        {
                                l++;
                        }
                        g.pb(l);
                }
        }
        int l = 1, r = 1e6;
        while(l < r)
        {
                int m = (l + r) / 2;
                if(can(m))
                {
                        r = m;
                }
                else
                {
                        l = m + 1;
                }
        }
        cout << l << endl;
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