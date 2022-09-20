#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300200;
const int mod = 1e9 + 7;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < int > res;
        int shit = 1;
        for(int i = 1; i < n; i++){
                if(__gcd(n, i) == 1){
                        res.push_back(i);
                        shit = 1ll * shit * i % n;
                }
        }
        if(shit != 1){
                res.pop_back();
        }

        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}