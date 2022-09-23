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
const long long MX = 2020;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];

void solve()
{
        cin >> n >> k;
        ll ans = 0;
        int mn = 1e9;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
                mn = min(mn, a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
                ll g = a[i] - mn;
                if(g % k)
                {
                        cout << "-1" << endl;
                        return;
                }
                ans += g / k;
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