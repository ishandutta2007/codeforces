#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
                if(k * 2 >= a[i]){
                        k = max(k, a[i]);
                        continue;
                }
                while(k * 2 < a[i]){
                        k = k * 2;
                        ans++;
                }
                k = max(k, a[i]);
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