#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2000;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
bitset < N > a[N];

void solve()
{
        cin >> n >> m;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        char c;
                        cin >> c;
                        a[i][j] = c - '0';
                }
        }
        for(int i = 0; i < n; i++){
                bitset < N > f;
                for(int j = 0; j < m; j++){
                        f[j] = 0;
                }
                for(int j = 0; j < n; j++){
                        if(i == j){
                                continue;
                        }
                        f |= a[j];
                }
                bool can = 1;
                for(int j = 0; j < m; j++){
                        can &= f[j];
                }
                if(can){
                        cout << "YES" << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
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