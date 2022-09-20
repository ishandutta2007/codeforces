#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

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
                for(int i = 0; i < n; i++){
                        char c;
                        cin >> c;
                        if(c == 'L' || c == 'R'){
                                cout << c;
                        } else if(c == 'D'){
                                cout << 'U';
                        } else{
                                cout << 'D';
                        }
                }
                cout << "\n";
        }
}