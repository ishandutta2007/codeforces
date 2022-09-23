#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 303;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

long long n, k;

void solve()
{
        cin >> n >> k;
        n /= k;
        if(n % 2){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}