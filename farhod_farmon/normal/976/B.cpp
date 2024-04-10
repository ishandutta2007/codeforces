#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

long long n, m, k;

void solve()
{
        cin >> n >> m >> k;
        if(k < n){
                cout << k + 1 << " " << 1 << "\n";
                return;
        }
        k -= n;
        int g = k % (m - 1);
        cout << n - k / (m - 1) << " ";
        if(k / (m - 1) % 2 == 0){
                cout << g + 2 << "\n";
        }
        else{
                cout << m - g << "\n";
        }
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