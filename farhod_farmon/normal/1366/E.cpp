#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 998244353;

using namespace std;

int n, m;
int a[N], b[N];
map < int, int > last;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                last[a[i]] = i;
        }
        for(int i = 0; i < m; i++){
                cin >> b[i];
        }
        vector < int > v;
        for(int i = n, mn = 1e9; i >= 1; i--){
                mn = min(mn, a[i]);
                if(a[i] == mn){
                        v.push_back(a[i]);
                }
        }
        reverse(v.begin(), v.end());
        vector < int > a(m, 0);
        long long res = 1;
        if(v[0] != b[0]){
                cout << 0 << "\n";
                return 0;
        }
        for(int i = 0, j = 0; i < v.size(); i++){
                while(j < m && b[j] < v[i]){
                        j += 1;
                }
                if(j < m && b[j] == v[i]){
                        if(j > 0 && !a[j]){
                                res = res * (last[b[j]] - last[v[i - 1]]) % mod;
                        }
                        a[j] = 1;
                }
        }
        for(int i = 1; i < m; i++){
                res *= a[i];
        }
        cout << res << "\n";
}