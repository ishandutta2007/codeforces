#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int x;
int a[N];
long long d[N];
long long f[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> x;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                f[i] = -1e18;
        }
        for(int i = 1; i <= x; i++){
                set < pair < long long, int > > s;
                for(int j = 1; j <= n; j++){
                        s.insert({f[j - 1], j - 1});
                        if(j - k - 1 >= 0){
                                s.erase({f[j - k - 1], j - k - 1});
                        }
                        d[j] = (--s.end())->fi + a[j];
                }
                for(int j = 1; j <= n; j++){
                        f[j] = d[j];
                }
        }
        long long ans = -1;
        for(int i = n - k + 1; i <= n; i++){
                ans = max(ans, f[i]);
        }
        cout << ans << "\n";
}