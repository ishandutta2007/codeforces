#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                vector < int > a(n);
                int cnt = 1;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0 && a[i] != a[i - 1]){
                                cnt += 1;
                        }
                }
                if(cnt == 1){
                        cout << 1 << "\n";
                        continue;
                } else if(k == 1){
                        cout << -1 << "\n";
                        continue;
                }
                int res = 1;
                cnt -= k;
                if(cnt > 0){
                        res += (cnt - 1) / (k - 1) + 1;
                }
                cout << res << "\n";
        }
}