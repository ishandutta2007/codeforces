#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                int bad = -1;
                if((n + m) % 2 == 0){
                        bad = (n + m) / 2 - 1;
                }
                vector < int > a(n + m + 1, 0);
                vector < int > b(n + m + 1, 0);
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                                int x;
                                cin >> x;
                                if(i + j == bad){
                                        continue;
                                }
                                int cur = (i + j);
                                cur = min(cur, n + m - cur - 2);
                                a[cur] += x;
                                b[cur] += 1 - x;
                        }
                }
                int res = 0;
                for(int i = 0; i < n + m; i++){
                        res += min(a[i], b[i]);
                }
                cout << res << "\n";

        }
}