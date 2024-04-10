#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
long long a[N];
long long b[N];

long long get(int x)
{
        for(int i = 0; i < n; i++){
                b[i] = a[i];
        }
        long long g = a[x];
        b[x] = 0;
        for(int i = x + 1; i < n && g > 0; i++, g--){
                b[i]++;
        }
        for(int i = 0; i < n; i++){
                b[i] += g / n;
        }
        g %= n;
        for(int i = 0; i < n && g > 0; i++, g--){
                b[i]++;
        }
        long long cnt = 0;
        for(int i = 0; i < n; i++){
                if(b[i] % 2 == 0){
                        cnt += b[i];
                }
        }
        return cnt;
}

void solve()
{
        n = 14;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        long long ans = 0;
        for(int j = 0; j < n; j++){
                ans = max(ans, get(j));
        }
        cout << ans << "\n";
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