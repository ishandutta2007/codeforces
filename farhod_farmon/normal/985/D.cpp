#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n, h;

long long get(long long n)
{
        long long l = 1, r = 2e9;
        while(l < r){
                long long m = (l + r) / 2 + 1;
                if(m * (m + 1) / 2 <= n){
                        l = m;
                }
                else{
                        r = m - 1;
                }
        }
        return l;
}

void solve()
{
        cin >> n >> h;
        long long g = get(n);
        if(g <= h){
                cout << g + ((n - g * (g + 1) / 2) > 0) << "\n";
                return;
        }
        long long l = 1, r = n / h;
        while(l < r){
                long long m = (l + r) / 2;
                long long f = m * h + m * (m - 1) / 2;
                if(f >= n){
                        r = m;
                }
                else{
                        if(get(n - f) > h + m - 1){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
        }
        n -= l * h + l * (l - 1) / 2;
        g = get(n);
        cout << l + g + ((n - g * (g + 1) / 2) > 0) << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}