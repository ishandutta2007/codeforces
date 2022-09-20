#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > c(3 * n + 1, 0);
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        c[x] += 1;
                }
                int res = 0, pre = 0;
                for(int i = 0; i + 1 < c.size(); i++){
                        if(c[i] + pre > 0){
                                res += 1;
                                pre = c[i] - (pre == 0);
                        } else{
                                pre = 0;
                        }
                }
                cout << res << "\n";
        }
}