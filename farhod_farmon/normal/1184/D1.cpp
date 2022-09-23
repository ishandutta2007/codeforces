#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int k;
int q;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k >> m >> q;
        while(q--){
                int t, x;
                cin >> t >> x;
                if(t == 1){
                        n += 1;
                        if(x <= k){
                                k += 1;
                        }
                } else{
                        if(k <= x){
                                n = x;
                        } else{
                                n -= x;
                                k -= x;
                        }
                }
                cout << n << " " << k << "\n";
        }
}