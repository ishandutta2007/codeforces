#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

ll n, k;

void solve()
{
        cin >> n >> k;
        ll x = (n / 2) / (k + 1);
        cout << x << " " << x * k << " " << n - x * (k + 1) << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}