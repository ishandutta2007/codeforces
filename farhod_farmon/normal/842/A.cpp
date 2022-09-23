#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

long long l, r, x, y, k;

void solve()
{
        cin >> l >> r >> x >> y >> k;
        swap(l, x); swap(r, y);
        while(l <= r){
                if(x <= l * k && l * k <= y){
                        cout << "YES" << "\n";
                        return;
                }
                l++;
        }
        cout << "NO" << "\n";
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