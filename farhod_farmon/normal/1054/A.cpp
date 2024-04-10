#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;


void solve()
{
        int x, y, z, t1, t2, t3;
        cin >> x >> y >> z >> t1 >> t2 >> t3;
        int a1 = abs(x - y) * t1;
        int a2 = 3 * t3 + abs(x - z) * t2 + abs(x - y) * t2;
        if(a1 < a2){
                cout << "NO" << "\n";
        }
        else{
                cout << "YES" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}