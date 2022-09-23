#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    if(s.size() == t.size() && s == t)
        cout << -1 << endl;
    else
        cout << max(s.size(), t.size()) << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}