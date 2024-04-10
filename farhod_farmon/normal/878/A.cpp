#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int d[10][2];

void solve()
{
        cin >> n;
        for(int i = 0; i < 10; i++){
                d[i][1] = 1;
        }
        for(int i = 1; i <= n; i++){
                char c;
                int x;
                cin >> c >> x;
                for(int j = 0; j < 10; j++){
                        for(int h = 0; h < 2; h++){
                                if(c == '|'){
                                        d[j][h] |= ((x & (1 << j)) > 0);
                                }
                                if(c == '&'){
                                        d[j][h] &= ((x & (1 << j)) > 0);
                                }
                                if(c == '^'){
                                        d[j][h] ^= ((x & (1 << j)) > 0);
                                }
                        }
                }
        }
        int x = 0, y = 0;
        for(int i = 0; i < 10; i++){
                if(d[i][0] == 1 && d[i][1] == 1){
                        x += (1 << i);
                }
                if(d[i][0] == 1 && d[i][1] == 0){
                        y += (1 << i);
                }
                if(d[i][0] == 0 && d[i][1] == 0){
                        x += (1 << i);
                        y += (1 << i);
                }
        }
        cout << 2 << "\n";
        cout << "| " << x << "\n";
        cout << "^ " << y << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}