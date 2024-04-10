#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

string s, t;

void solve()
{
        cin >> s >> t;
        int c = 1;
        while((int)s.size() - c >= 0 && (int)t.size() - c >= 0 && s[s.size() - c] == t[t.size() - c]){
                c++;
        }
        cout << s.size() + t.size() - 2 * (c - 1) << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}