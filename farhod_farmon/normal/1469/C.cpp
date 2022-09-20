#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                int l = -1e9, r = 1e9, res = 1;
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        l = max(l - (k - 1), x);
                        r = min(r + (k - 1), x + (i != 0 && i != n - 1 ? k - 1 : 0));
                        if(l > r){
                                res = 0;
                        }
                }
                cout << (res ? "Yes" : "No") << "\n";
        }
}