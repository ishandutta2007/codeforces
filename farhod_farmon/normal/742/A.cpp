#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;

void solve()
{
        cin >> n;
        if(n == 0){
                cout << 1 << "\n";
        }
        else if(n % 4 == 0){
                cout << 6 << "\n";
        }
        else if(n % 4 == 1){
                cout << 8 << "\n";
        }
        else if(n % 4 == 2){
                cout << 4 << "\n";
        }
        else{
                cout << 2 << "\n";
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