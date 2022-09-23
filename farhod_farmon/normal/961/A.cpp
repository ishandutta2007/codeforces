#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int a[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                a[x]++;
        }
        int ans = m;
        for(int i = 1; i <= n; i++){
                ans = min(ans, a[i]);
        }
        cout << ans << "\n";
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