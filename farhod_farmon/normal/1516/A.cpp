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
                int n, k;
                cin >> n >> k;
                vector < int > a(n);
                for(int &x: a){
                        cin >> x;
                }
                for(int i = 0; i < n - 1; i++){
                        while(a[i] > 0 && k > 0){
                                a[i] -= 1;
                                k -= 1;
                                a[n - 1] += 1;
                        }
                }
                for(int x: a){
                        cout << x << " ";
                }
                cout << "\n";
        }
}