#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;

void solve()
{
        cin >> n;
        int cnt = 0;
        for(int a = 1; a <= n; a++){
                for(int b = a; b <= n; b++){
                        int c = a ^ b;
                        if(c >= b && a + b > c && c <= n){
                                cnt++;
                        }
                }
        }
        cout << cnt << "\n";
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