#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x[1001005];
ll a,b,ans=9e18,sum[29][1001005];
vector<int> v;

void add(int cur) {
    for (int i = 2; i * i <= cur; ++i) {
        if (cur % i == 0) {
            int curg = 1;
            for (int j = 0; j < v.size(); ++j)
                curg &= v[j] != i;
            if (curg)
                v.push_back(i);
            while (cur % i == 0)
                cur /= i;
        }
    }
    if (cur > 1) {
        int curg = 1;
        for (int j = 0; j < v.size(); ++j)
            curg &= v[j] != cur;
        if (curg)
            v.push_back(cur);
    }
    sort(v.begin(), v.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    ans = ll(n - 1) * ll(a);
    for (int TTT = 0; TTT < 2; ++TTT) {
        add(x[0] - 1);
        add(x[0]);
        add(x[0] + 1);

        for (int j = 0; j < v.size(); ++j) {
            for (int i = n-1; i >= 0; --i) {
                if (i == n-1) sum[j][i+1] = n * a;
                if (sum[j][i+1] == ll(9e18)) { sum[j][i] = 9e18; continue; }
                if (x[i] % v[j] == 0)
                    sum[j][i] = sum[j][i+1] - a;
                else if ((x[i] + 1) % v[j] == 0 || (x[i] - 1) % v[j] == 0)
                    sum[j][i] = sum[j][i+1] - a + b;
                else
                    sum[j][i] = 9e18;
            }
        }

        for (int j = 0; j < v.size(); ++j) {
            for (int i = n-1; i >= 0; --i) {
                sum[j][i] = min(sum[j][i], sum[j][i+1]);
            }
        }

        for (int j = 0; j < v.size(); ++j) {
            ll cursum = 0;
            for (int i = 0; i < n; ++i) {
                if (x[i] % v[j] == 0) { }
                else if ((x[i] + 1) % v[j] == 0 || (x[i] - 1) % v[j] == 0) cursum += b;
                else { break; }

                if (i == n-1) ans = min(ans, cursum);
                else if (sum[j][i+1] == ll(9e18)) break;
                else ans = min(ans, cursum + sum[j][i+1] - ll(i + 1) * ll(a));
            }
        }

        for (int i = 0; i < 29; ++i) {
            for (int j = 0; j < 1001005; ++j)
                sum[i][j] = 0;
        }
        v.clear();
        reverse(x, x + n);
    }
    cout << ans;

    return 0;
}