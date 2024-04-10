#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int q;
int f[Q];
int d[10][Q];

void solve()
{
        for(int i = 1; i < Q; i++){
                if(i < 10){
                        f[i] = i;
                }
                else{
                        int p = 1, y = i;
                        while(y){
                                if(y % 10 > 0){
                                        p *= y % 10;
                                }
                                y /= 10;
                        }
                        f[i] = f[p];
                }
                for(int j = 1; j <= 9; j++){
                        d[j][i] = d[j][i - 1];
                }
                d[f[i]][i]++;
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
                int l, r, k;
                cin >> l >> r >> k;
                cout << d[k][r] - d[k][l - 1] << "\n";
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