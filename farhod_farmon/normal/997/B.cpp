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

long long n;
bool used[15 * 50][15];

int f(int x, int l)
{
        if(used[x][l]){
                return 0;
        }
        used[x][l] = 1;
        if(l == n){
                return 1;
        }
        return f(x + 1, l + 1) + f(x + 5, l + 1) + f(x + 10, l + 1) + f(x + 50, l + 1);
}

void solve()
{
        cin >> n;
        if(n < 12){
                cout << f(0, 0) << "\n";
        }
        else{
                cout << 292 + (n - 11) * 49 << "\n";
        }
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