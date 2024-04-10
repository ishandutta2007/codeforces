#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
long long f[11];
long long d[11];

vector < pair < long long, long long > > get()
{
        int k;
        cin >> k;
        vector < long long > a[3];
        for(int i = 1; i <= k; i++){
                int x, y;
                cin >> x >> y;
                a[x - 1].push_back(y);
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        sort(a[2].begin(), a[2].end());
        reverse(a[0].begin(), a[0].end());
        reverse(a[1].begin(), a[1].end());
        reverse(a[2].begin(), a[2].end());
        vector < pair < long long, long long > > res(3);
        for(int i = 0; i < 3; i++){
                a[i].push_back(-1e17);
                a[i].push_back(-1e17);
                a[i].push_back(-1e17);
        }
        res[0].fi = max(a[0][0], max(a[1][0], a[2][0]));
        res[1].fi = max(a[0][0] + a[1][0], a[0][0] + a[0][1]);
        res[2].fi = a[0][0] + a[0][1] + a[0][2];
        res[0].se = res[0].fi * 2;
        res[1].se = max(a[0][0] + a[1][0] + max(a[0][0], a[1][0]), 2 * a[0][0] + a[0][1]);
        res[2].se = res[2].fi + a[0][0];
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < 10; i++){
                d[i] = f[i] = -1e18;
        }
        d[0] = 0;
        for(int i = 1; i <= n; i++){
                auto v = get();
                for(int j = 0; j < 10; j++){
                        for(int h = 0; h < 3; h++){
                                int nj = (j + h + 1) % 10;
                                if(j + h + 1 >= 10){
                                        f[nj] = max(f[nj], d[j] + v[h].se);
                                } else{
                                        f[nj] = max(f[nj], d[j] + v[h].fi);
                                }
                        }
                }
                for(int j = 0; j < 10; j++){
                        d[j] = max(d[j], f[j]);
                        f[j] = -1e18;
                }
        }
        long long res = 0;
        for(int i = 0; i < 10; i++){
                res = max(res, d[i]);
        }
        cout << res << "\n";
}