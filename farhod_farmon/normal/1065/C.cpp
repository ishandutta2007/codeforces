#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int a[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x]++;
        }
        int s = 0, ans = 0;
        for(int i = N - 1; i >= 1; i--){
                if(a[i] == n){
                        ans += (s > 0);
                        break;
                }
                if(s + a[i] > k){
                        ans++;
                        s = 0;
                }
                s += a[i];
                a[i - 1] += a[i];
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