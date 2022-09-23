#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 998244353;

using namespace std;

int n, m;
int a[N];
int b[N];
int c[N];
long long cost[N];
long long d[N];
long long f[N];
map < int, int > id;

long long f1[N];
long long f2[N];
long long t[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

long long get(int x)
{
        long long res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

vector < pair < int, int > > ord;

long long GET(int x)
{
        int l = lower_bound(ord.begin(), ord.end(), make_pair(x + 1, 0)) - ord.begin();
        l -= 1;
        if(l >= 0){
                return get(ord[l].se);
        }
        return 0;
}

void build()
{
        for(int i = 1; i <= n; i++){
                ord.push_back({a[i], i});
        }
        sort(ord.begin(), ord.end());
        for(int i = 0, j = 1; i < ord.size(); i++){
                if(i > 0 && ord[i].fi > ord[i - 1].fi){
                        j += 1;
                }
                a[ord[i].se] = j;
                ord[i].se = j;
        }

        for(int i = n; i >= 1; i--){
                if(c[i] != -1){
                        int j = c[i];
                        f1[i] = GET(b[j]);
                        f2[i] = GET(b[j - 1]);

                        //for(int h = i + 1; h <= n; h++){
                        //        if(a[h] <= b[j]) f1[i] += cost[h];
                        //        if(a[h] <= b[j - 1]) f2[i] += cost[h];
                        //}
                }
                if(cost[i] > 0){
                        upd(a[i], cost[i]);
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        for(int i = 1; i <= n; i++) scanf("%lld", cost + i);
        scanf("%d", &m);
        long long inf = (long long)1e18;
        for(int i = 1; i <= m; i++){
                scanf("%d", b + i);
                id[b[i]] = i;
                d[i] = f[i] = inf;
        }
        for(int i = 1; i <= n; i++){
                if(id.find(a[i]) != id.end()){
                        c[i] = id[a[i]];
                } else{
                        c[i] = -1;
                }
        }

        build();

        for(int i = 1; i <= n; i++) cost[i] += cost[i - 1];

        long long res = inf;
        for(int i = 1; i <= n; i++){

                int j = c[i];
                if(j == -1 || d[j - 1] == inf){
                        continue;
                }
                long long cur = f[j - 1] + cost[i - 1] + f2[i];
                if(j == 1){
                        cur = cost[i - 1];
                }
                d[j] = min(d[j], cur);
                f[j] = min(f[j], cur - cost[i] - f1[i]);

                if(j == m){
                        res = min(res, cur + cost[n] - cost[i] - f1[i]);
                }

        }
        if(res == inf){
                printf("NO\n");
        } else{
                printf("YES\n");
                printf("%lld\n", res);
        }
}