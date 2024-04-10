#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;
const int mod = 998244353;

int n;
long long a[N], b[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > v;
        long long res = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                v.push_back(i);
                res += b[i];
        }
        sort(v.begin(), v.end(), [&](int i, int j){ return a[i] < a[j]; });
        int h;
        for(int i = 0; i < n; i++){
                if(v[i] == 1){
                        h = i;
                }
        }
        long long shit = b[v[0]];
        for(int i = 1; i < n; i++){
                res += max(0ll, a[v[i]] - a[v[i - 1]] - shit);
                shit = max(shit - (a[v[i]] - a[v[i - 1]]), b[v[i]]);
        }
        /*
        shit = b[v[h]];
        for(int i = h + 1; i < n; i++){
                res += max(0ll, a[v[i]] - a[v[i - 1]] - shit);
                shit = max(shit - (a[v[i]] - a[v[i - 1]]), b[v[i]]);
        }
        */

        cout << res << "\n";
}