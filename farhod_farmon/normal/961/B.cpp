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
int k;
int a[N];
int s[N];
int t[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] + a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> t[i];
                t[i] = t[i - 1] + t[i] * a[i];
        }
        int ans = 0;
        for(int i = 1; i + k - 1 <= n; i++){
                ans = max(ans, t[i - 1] + (t[n] - t[i + k - 1]) + (s[i + k - 1] - s[i - 1]));
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