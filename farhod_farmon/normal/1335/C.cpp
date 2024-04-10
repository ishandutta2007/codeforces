#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n + 1, 0);
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        a[x] += 1;
                }
                int res = 0, dif = 0;
                for(int i = 1; i <= n; i++) if(a[i] > 0) dif += 1;

                for(int i = 1; i <= n; i++){
                        if(a[i] == 0){
                                continue;
                        }
                        res = max(res, min(a[i], dif - 1));
                        res = max(res, min(a[i] - 1, dif));
                }
                cout << res << "\n";
        }
}