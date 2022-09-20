#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000011;
const int mod = 998244353;

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
                vector < int > a(2 * n);
                for(int i = 0; i < 2 * n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                for(int i = 0; i < 2 * n; i++){
                        if(i % 2 == 0){
                                cout << a[i / 2] << " ";
                        } else{
                                cout << a[n + i / 2] << " ";
                        }
                }
                cout << "\n";
        }
}