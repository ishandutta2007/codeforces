#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 70070;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];

int f(int x, int y)
{
        int cnt = 0, last = -1;
        for(int i = 1; i <= n; i++){
                if(i == x || i == y){
                        continue;
                }
                if(last != -1){
                        cnt += a[i] - last;
                        last = -1;
                }
                else{
                        last = a[i];
                }
        }
        return cnt;
}

void solve()
{
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 1e9;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        ans = min(ans, f(i, j));
                }
        }
        cout << ans << "\n";
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