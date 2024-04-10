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

int h, x, m;

bool good(int x, int y)
{
        for(int i = 0; i < 3; i++){
                if(x % 10 == 7 || y % 10 == 7){
                        return true;
                }
                x /= 10; y /= 10;
        }
        return false;
}

void solve()
{
        cin >> x >> h >> m;
        for(int i = 0; ; i++){
                if(good(h, m)){
                        cout << i << endl;
                        break;
                }
                m -= x;
                if(m < 0){
                        m += 60;
                        h -= 1;
                }
                if(h < 0){
                        h += 24;
                }
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