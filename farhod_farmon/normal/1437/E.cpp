#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int inf = (1e9) + (1e6);

int n;
int k;
int a[N];

int solve(int l, int r)
{
        int X = a[l], Y = a[r];
        if(X > Y){
                cout << -1 << "\n";
                exit(0);
        }
        vector < int > v(r - l + 2, inf);
        v[0] = - inf;
        int res = 0;
        for(int i = l + 1; i < r; i++){
                if(a[i] < X || a[i] > Y){
                        continue;
                }
                int j = lower_bound(v.begin(), v.end(), a[i] + 1) - v.begin();
                v[j] = a[i];
                res = max(res, j);
        }
        return r - l - 1 - res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        a[0] = - inf;
        a[n + 1] = inf;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= i;
        }
        vector < int > b(k + 1);
        b[0] = 0;
        for(int i = 1; i <= k; i++){
                cin >> b[i];
        }
        b.push_back(n + 1);
        sort(b.begin(), b.end());

        int res = 0;
        for(int i = 0; i <= k; i++){
                res += solve(b[i], b[i + 1]);
        }

        cout << res << "\n";
}