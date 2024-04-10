#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 505;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, a, b;

void solve()
{
        cin >> n >> a >> b;
        for(int x = 0; x * a <= n; x++){
                int y = (n - x * a) / b;
                if(x * a + y * b == n){
                        cout << "YES" << "\n";
                        cout << x << " " << y << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}