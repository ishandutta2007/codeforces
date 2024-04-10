#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 10000001;
const long long mod = 1e9 + 7;

using namespace std;

int a, b;

void solve()
{
    cin >> a >> b;
    if(abs(a - b) <= 1 && (a != 0 || b != 0))
        cout << "YES";
    else
        cout << "NO";
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