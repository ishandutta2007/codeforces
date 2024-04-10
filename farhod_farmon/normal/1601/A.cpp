#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400200;

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
                int n;
                cin >> n;
                vector<int> c(30, 0);
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        for(int j = 0; j < 30; j++){
                                if(x & (1 << j)){
                                        c[j] += 1;
                                }
                        }
                }
                int res = 0;
                for(int i = 0; i < 30; i++){
                        if(c[i]){
                                res = __gcd(res, c[i]);
                        }
                }
                for(int i = 1; i <= n; i++){
                        if(res % i == 0){
                                cout << i << " ";
                        }
                }
                cout << "\n";
        }
}