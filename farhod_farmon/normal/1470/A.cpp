#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                vector < int > c(m, 1);
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        c[x - 1] += 1;
                }
                vector < int > v;
                long long res = 0;
                for(int i = 0; i < m; i++){
                        int x;
                        cin >> x;
                        while(c[i] > 0 && n > 0){
                                c[i] -= 1;
                                n -= 1;
                                res += x;
                        }
                }
                cout << res << "\n";
        }
}