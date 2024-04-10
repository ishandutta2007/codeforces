#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N];
int b[N];
long long ans[N];
pair < int, int > p[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                p[i] = {a[i] - b[i], i};
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        sort(p + 1, p + n + 1);
        long long s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i++){
                s2 += b[i];
        }
        for(int i = 1; i <= n; i++){
                int j = p[i].se;
                s2 -= b[j];
                ans[j] += 1ll * (n - i) * a[j] + s2;
                ans[j] += 1ll * (i - 1) * b[j] + s1;
                for(int h: v[j]){
                        ans[j] -= min(a[j] + b[h], b[j] + a[h]);
                }
                s1 += a[j];
        }
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}