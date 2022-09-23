#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long n;

int get(long long x)
{
        long long y = n;
        int cnt = 0;
        while(y){
                if(x > 0 && y % 10 == x % 10){
                        x /= 10;
                }
                else{
                        cnt++;
                }
                y /= 10;
        }
        if(x > 0){
                cnt = 1e9;
        }
        return cnt;
}

void solve()
{
        cin >> n;
        long long bad = 1e9;
        for(long long i = 1; i * i <= n; i++){
                int g = get(i * i);
                if(g < bad){
                        bad = g;
                }
        }
        if(bad == 1e9){
                bad = -1;
        }
        cout << bad << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}