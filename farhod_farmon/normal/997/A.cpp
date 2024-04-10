#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
long long x, y;

void solve()
{
        cin >> n >> x >> y;
        long long cnt = 0, f = 0;
        for(int i = 1; i <= n + 1; i++){
                char c;
                if(i <= n){
                        cin >> c;
                }
                else{
                        c = '1';
                }
                if(c == '0'){
                        f = 1;
                }
                else{
                        cnt += f;
                        f = 0;
                }
        }
        if(cnt == 0){
                cout << 0 << "\n";
        }
        else if(x >= y){
                cout << cnt * y << "\n";
        }
        else{
                cout << (cnt - 1) * x + y << "\n";
        }
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