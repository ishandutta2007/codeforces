#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, m, k;
                cin >> n >> m >> k;
                vector<int> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                vector<int> b(m);
                for(int i = 0; i < m; i++){
                        cin >> b[i];
                }
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());

                vector<vector<int>> A(n), B(m);

                for(int i = 0; i < k; i++){
                        int x, y;
                        cin >> x >> y;

                        int j = lower_bound(a.begin(), a.end(), x) - a.begin();
                        int h = lower_bound(b.begin(), b.end(), y) - b.begin();

                        if(a[j] == x && b[h] == y){
                                continue;
                        } else if(a[j] == x){
                                B[h].push_back(j);
                        } else{
                                A[j].push_back(h);
                        }
                }

                auto solve = [&](vector<int> &v) -> long long
                {
                        long long res = 0;
                        sort(v.begin(), v.end());
                        for(int i = 0, j = 1, h = 0; i < v.size(); i++){
                                if(i + 1 < v.size() && v[i] == v[i + 1]){
                                        j += 1;
                                        continue;
                                }
                                res += 1ll * j * h;
                                h += j;
                                j = 1;
                        }
                        return res;
                };

                long long res = 0;
                for(int i = 0; i < n; i++){
                        res += solve(A[i]);
                }
                for(int i = 0; i < m; i++){
                        res += solve(B[i]);
                }

                cout << res << "\n";
        }
}