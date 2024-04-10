#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int l;
long long a[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> l;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] > l && a[i - 1] <= l){
                        ans++;
                }
        }
        for(int i = 1; i <= m; i++){
                int t;
                int x, y;
                cin >> t;
                if(t == 0){
                        cout << ans << "\n";
                        continue;
                }
                cin >> x >> y;
                if(a[x] > l){
                        continue;
                }
                a[x] += y;
                if(a[x] > l){
                        ans += a[x - 1] <= l;
                        ans -= a[x + 1] > l;
                }
        }
}