#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 1000000009;
const long long block = 500;

using namespace std;

int n;
int x;
int k;
int a[N];

int f(int y)
{
        return y / x;
}

void solve()
{
        cin >> n >> x >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        long long ans = 0, l = 1, r = 1;
        for(int i = 1; i <= n; i++){
                while(l <= i && f(a[i]) - f(a[l] - 1) > k){
                        l++;
                }
                while(r <= i && f(a[i]) - f(a[r] - 1) >= k){
                        r++;
                }
                ans += r - l;
        }
        for(int i = 1; i <= n; i++){
                int cnt = 0;
                while(i + cnt <= n && a[i] == a[i + cnt]){
                        cnt++;
                }
                if(f(a[i]) - f(a[i] - 1) == k){
                        ans += 1ll * cnt * cnt - 1ll * cnt * (cnt + 1) / 2;
                }
                i += cnt - 1;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("park.in");
        //fout("park.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}