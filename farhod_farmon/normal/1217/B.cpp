#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int max_dif = -1e9, max_d = -1e9;
                int n, x;
                cin >> n >> x;
                for(int i = 1; i <= n; i++){
                        int d, h;
                        cin >> d >> h;
                        max_dif = max(max_dif, d - h);
                        max_d = max(max_d, d);
                }
                int res = 1;
                if(x > max_d){
                        if(max_dif <= 0){
                                res = -1;
                        } else{
                                res += (x - max_d - 1) / max_dif + 1;
                        }
                }
                cout << res << "\n";
        }
}