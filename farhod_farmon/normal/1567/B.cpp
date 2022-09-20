#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 998244353;

using namespace std;


int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        vector<int> d(N, 0);
        for(int i = 1; i < N; i++){
                d[i] = d[i - 1] ^ i;
        }

        int t;
        cin >> t;
        while(t--){
                int a, b;
                cin >> a >> b;
                b ^= d[a - 1];
                if(b == 0){
                        cout << a << "\n";
                } else if(b != a){
                        cout << a + 1 << "\n";
                } else{
                        cout << a + 2 << "\n";
                }
        }
}