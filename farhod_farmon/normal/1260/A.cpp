#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
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
                long long res = 0, cost = k / n, shit = k % n;
                if(shit > 0){
                        cost += 1;
                }
                for(int i = 0; i < n; i++){
                        shit -= 1;
                        res += cost * cost;
                        if(shit == 0){
                                cost -= 1;
                        }
                }
                cout << res << "\n";
        }
}