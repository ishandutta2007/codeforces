#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 220;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int d[4 * N][4 * N];

void solve()
{
        int a, b, ax = 100, ay = -100, bx = 100, by = -100;
        for(int i = 0; i < 4; i++){
                cin >> a >> b;
                ax = min(ax, a);
                ay = max(ay, a);
                bx = min(bx, b);
                by = max(by, b);
        }
        ax += N; ay += N; bx += N; by += N;
        for(int i = ax; i <= ay; i++){
                for(int j = bx; j <= by; j++){
                        d[i][j]++;
                }
        }
        ax = 100, ay = -100, bx = 100, by = -100;
        for(int i = 0; i < 4; i++){
                cin >> a >> b;
                ax = min(ax, a);
                ay = max(ay, a);
                bx = min(bx, b);
                by = max(by, b);
        }
        ax += N; ay += N; bx += N; by += N;
        for(int i = ax; i <= ay; i++){
                int l, r;
                if(i - ax <= (ay - ax) / 2){
                        l = (bx + by) / 2 - (i - ax);
                        r = (bx + by) / 2 + (i - ax);
                }
                else{
                        l = bx + (i - ax - (ay - ax) / 2);;
                        r = by - (i - ax - (ay - ax) / 2);;
                }
                for(int j = l; j <= r; j++){
                        d[i][j]++;
                }
        }
        for(int i = 0; i < 4 * N; i++){
                for(int j = 0; j < 4 * N; j++){
                        if(d[i][j] > 1){
                                cout << "YES" << "\n";
                                return;
                        }
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