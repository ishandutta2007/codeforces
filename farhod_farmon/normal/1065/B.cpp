#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 660;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

long long n, m;

void solve()
{
        cin >> n >> m;
        cout << max(n - m - m, 0ll) << " ";
        for(long long i = 0; i <= n; i++){
                if(i * (i - 1) / 2 >= m){
                        cout << n - i << "\n";
                        break;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}