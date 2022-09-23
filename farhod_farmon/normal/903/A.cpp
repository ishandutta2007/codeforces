#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        bool f = 0;
        for(int i = 0; i * 3 <= n; i++){
                f |= ((n - i * 3) % 7 == 0);
        }
        if(f){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}

bool mtest = true; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}