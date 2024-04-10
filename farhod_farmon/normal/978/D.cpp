#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int b[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        if(n <= 2){
                cout << 0 << "\n";
                return;
        }
        int ans = 1e9;
        for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                        int d = (a[2] + y) - (a[1] + x), cnt = abs(x) + abs(y);
                        bool cor = true;
                        b[2] = a[2] + y;
                        for(int i = 3; i <= n; i++){
                                b[i] = -1;
                                for(int h = -1; h <= 1; h++){
                                        if(a[i] + h - b[i - 1] == d){
                                                b[i] = a[i] + h;
                                                cnt += abs(h);
                                                break;
                                        }
                                }
                                if(b[i] == -1){
                                        cor = false;
                                        break;
                                }
                        }
                        if(cor){
                                ans = min(ans, cnt);
                        }
                }
        }
        if(ans == 1e9){
                ans = -1;
        }
        cout << ans << "\n";
;}

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