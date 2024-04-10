#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 50050;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n;

bool can(long long k)
{
        long long c = 0, x = n;
        while(x){
                c += min(k, x);
                x -= min(k, x);
                x -= x / 10;
        }
        return c >= (n + 1) / 2;
}

void solve()
{
        cin >> n;
        long long l = 1, r = 1e18;
        while(l < r){
                long long m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
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