#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int d[N];
int p[N];
map < int, int > f;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int ans = 0, h;
        for(int i = n; i >= 1; i--){
                if(f.find(a[i] + 1) != f.end()){
                        p[i] = f[a[i] + 1];
                        d[i] = d[p[i]] + 1;
                }
                else{
                        d[i] = 1;
                }
                f[a[i]] = i;
                if(d[i] > ans){
                        ans = d[i];
                        h = i;
                }
        }
        cout << ans << "\n";
        while(ans--){
                cout << h << " ";
                h = p[h];
        }
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