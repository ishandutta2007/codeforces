#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n, k;
                cin >> n >> k;
                int l = 1, r = 1e9;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        l = max(l, x - k);
                        r = min(r, x + k);
                }
                if(l <= r){
                        cout << r << "\n";
                } else{
                        cout << -1 << "\n";
                }
        }
}