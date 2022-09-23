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

string s, t = "AHIMOTUVWXY";
char c[200];

void solve()
{
        cin >> s;
        for(int i = 0; i < t.size(); i++)
        {
                c[t[i]] = t[i];
        }
        for(int i = 0; i < s.size(); i++)
        {
                if(s[i] != c[s[s.size() - i - 1]])
                {
                        cout << "NO" << endl;
                        return;
                }
        }
        cout << "YES" << endl;
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