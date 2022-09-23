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
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

char c[N];
string s, ans;
vector < char > v;

void solve()
{
        cin >> s;
        c[s.size()] = 'z';
        for(int i = s.size() - 1; i >= 0; i--)
        {
                c[i] = min(s[i], c[i + 1]);
        }
        for(int i = 0; i < s.size(); i++)
        {
                while(!v.empty() && v.back() <= c[i])
                {
                        ans += v.back();
                        v.pop_back();
                }
                v.pb(s[i]);
        }
        while(!v.empty())
        {
                ans += v.back();
                v.pop_back();
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