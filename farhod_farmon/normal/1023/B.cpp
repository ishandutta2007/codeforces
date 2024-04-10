#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n, k;

long long f(long long x)
{
        return max(x, k - x);
}

void solve()
{
        cin >> n >> k;
        long long l = 1, r = k / 2;
        if(f(r) > n){
                cout << 0 << "\n";
                return;
        }
        while(l < r){
                long long m = (l + r) / 2;
                if(f(m) <= n){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        cout << k / 2 - l + (k % 2) << "\n";
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