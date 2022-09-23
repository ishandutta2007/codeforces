#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n, pos, l, r;

void solve()
{
        cin >> n >> pos >> l >> r;
        if(l == 1 && r == n){
                cout << 0 << "\n";
        }
        else if(l == 1){
                cout << abs(pos - r) + 1 << "\n";
        }
        else if(r == n){
                cout << abs(pos - l) + 1 << "\n";
        }
        else{
                cout << min(abs(pos  - l), abs(pos - r)) + r - l + 2 << "\n";
        }
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