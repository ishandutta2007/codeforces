#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

long long l, r;
long long d[80][3][3][3][3];

bool can(int p, int &tl, int &tr, int x)
{
        if(x == 0){
                tr |= ((r >> p) & 1);
                if(tl == 1){
                        return true;
                }
                return ((l >> p) & 1) == 0;
        }
        tl |= (((l >> p) & 1) ^ 1);
        if(tr == 1){
                return true;
        }
        return ((r >> p) & 1) == 1;
}

long long f(int p, int l1, int r1, int l2, int r2)
{
        if(p < 0){
                return 0;
        }
        long long &x = d[p][l1][r1][l2][r2];
        if(x){
                return x;
        }
        x = -2e18;
        for(int i = 0; i <= 1; i++){
                for(int j = 0; j <= 1; j++){
                        int nl1 = l1, nl2 = l2, nr1 = r1, nr2 = r2;
                        if(can(p, nl1, nr1, i) && can(p, nl2, nr2, j)){
                                x = max(x, (1ll << p) * (i ^ j) + f(p - 1, nl1, nr1, nl2, nr2));
                        }
                }
        }
        return x;
}

void solve()
{
        cin >> l >> r;
        cout << f(60, 0, 0, 0, 0) << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}