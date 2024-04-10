#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

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
                int a, b;
                cin >> a >> b;
                if(a % 2 != b % 2){
                        cout << -1 << "\n";
                } else if(a + b == 0){
                        cout << 0 << "\n";
                } else if(a == b){
                        cout << 1 << "\n";
                } else{
                        cout << 2 << "\n";
                }
        }
}