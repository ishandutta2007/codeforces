#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, u, v;
                cin >> n >> u >> v;
                int res = 0;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i > 0){
                                res = max(res, abs(a[i] - a[i - 1]));
                        }
                }
                res = min(res, 2);
                if(res == 2){
                        cout << 0 << "\n";
                } else if(res == 1){
                        cout << min(u, v) << "\n";
                } else{
                        cout << min(u, v) + v << "\n";
                }
        }
}