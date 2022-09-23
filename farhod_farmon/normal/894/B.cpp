#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

long long pw(long long x, long long n)
{
        if(n == 0){
                return 1;
        }
        if(n % 2){
                return (x * pw(x, n - 1)) % mod;
        }
        else{
                return pw((x * x) % mod, n / 2);
        }
}

long long n, m, k;

void solve()
{
        cin >> n >> m >> k;
        if((n + m) % 2 && k == -1){
                cout << 0 << "\n";
        }
        else{
                cout << pw(pw(2, n - 1), m - 1) << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}