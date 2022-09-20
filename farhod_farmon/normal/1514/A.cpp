#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300200;


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
                int res = 0;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        int y = sqrt(x);
                        if(y * y != x){
                                res = 1;
                        }
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}