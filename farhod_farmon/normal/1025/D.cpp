#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 710;
const long long Q = 10100;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int d[N][N][2];
bool c[N][N];

bool can(int l, int r, int g)
{
        if(1.0 * clock() / CLOCKS_PER_SEC > 0.96){
                return false;
        }
        if(l > r){
                return true;
        }
        if(l == r){
                if(g == 0){
                        return c[l][l - 1];
                }
                return c[l][l + 1];
        }
        int &gg = d[l][r][g];
        if(gg){
                return gg - 1;
        }
        gg = 1;
        for(int i = l; i <= r; i++){
                if((g == 0 && c[i][l - 1]) || (g == 1 && c[i][r + 1])){
                        if(can(l, i - 1, 1) && can(i + 1, r, 0)){
                                gg = 2;
                                return 1;
                        }
                }
        }
        return gg - 1;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 1; j < i; j++){
                        if(__gcd(a[i], a[j]) > 1){
                                c[i][j] = c[j][i] = 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                if(can(1, i - 1, 1) && can(i + 1, n, 0)){
                        cout << "Yes" << "\n";
                        return;
                }
        }
        cout << "No" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}