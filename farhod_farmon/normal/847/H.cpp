#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int l[N];
int r[N];
long long dl[N];
long long dr[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                l[i] = max(l[i - 1] + 1, a[i]);
                dl[i] = dl[i - 1] + l[i] - a[i];
        }
        for(int i = n; i >= 1; i--){
                r[i] = max(r[i + 1] + 1, a[i]);
                dr[i] = dr[i + 1] + r[i] - a[i];
        }
        long long ans = min(dl[n], dr[1]);
        for(int i = 1; i < n; i++){
                int x = l[i], y = r[i + 1];
                ans = min(ans, dl[i] + dr[i + 1] + max(0, y - x + 1));
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