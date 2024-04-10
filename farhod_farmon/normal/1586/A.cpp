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
                int ban = -1, s = 0;
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        s += x;
                        if(x % 2){
                                ban = i;
                        }
                }
                bool good = 0;
                for(int i = 2; i * i <= s; i++){
                        if(s % i == 0){
                                good = 1;
                        }
                }
                if(good){
                        ban = -1;
                        cout << n << "\n";
                } else{
                        cout << n - 1 << "\n";
                }
                for(int i = 1; i <= n; i++) if(i != ban){
                        cout << i << " ";
                }
                cout << "\n";
        }
}