#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                int n, x;
                cin >> n >> x;
                vector < int > a(n);
                int all = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        all += a[i];
                }
                if(all == x){
                        cout << "NO" << "\n";
                        continue;
                }
                sort(a.begin(), a.end());
                int s =0;
                for(int i = 0; i < n; i++){
                        s += a[i];
                        if(s == x){
                                swap(a[i], a[n - 1]);
                                break;
                        }
                }
                cout << "YES" << "\n";
                for(int x: a){
                        cout << x << " ";
                }
                cout << "\n";
        }
}