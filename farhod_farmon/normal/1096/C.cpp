#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 180;
const long long mod = 998244353;

using namespace std;

int res[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        for(int n = 3; n <= 5000; n++){
                int s = 180 * (n - 2), g = n * (n - 2);
                for(int i = 1; i < n - 1; i++){
                        if(s * i % g == 0){
                                int a = s * i / g;
                                if(res[a] == 0){
                                        res[a] = n;
                                }
                        }
                }
        }
        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                cout << res[n] << "\n";
        }
}