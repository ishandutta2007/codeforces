#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1000010;

using namespace std;

int n;
int e;
int c[Q];
int f[Q];

void solve()
{
        cin >> n >> e;
        vector<vector<int>> a(e);
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[i % e].push_back(c[x]);
        }

        long long res = 0;
        for(int i = 0; i < e; i++){
                int sum = 0;
                f[0] = 1;
                for(int x : a[i]){
                        sum += x;
                        if(sum > 0){
                                res += f[sum - 1] - (x == 1);
                        }
                        f[sum] += 1;
                }
                for(int j = 0; j <= sum; j++){
                        f[j] = 0;
                }
        }
        cout << res << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        for(int i = 2; i < Q; i++){
                if(c[i]){
                        continue;
                }
                c[i] = 1;
                for(int j = i * 2; j < Q; j += i){
                        c[j] = 2;
                }
        }

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}