#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

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
                int l, r;
                cin >> l >> r;
                if(l * 2 > r){
                        cout << r - l << "\n";
                } else{
                        cout << (r - 1) / 2 << "\n";
                }
        }
}