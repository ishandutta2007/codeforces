#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;

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
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= i; j++){
                                cout << "(";
                        }
                        for(int j = 1; j <= i; j++){
                                cout << ")";
                        }
                        for(int j = 1; j <= (n - i); j++){
                                cout << "()";
                        }
                        cout << "\n";
                }
        }
}