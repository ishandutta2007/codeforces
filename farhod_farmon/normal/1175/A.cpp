#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long n, k;
                cin >> n >> k;
                long long res = 0;
                while(n > 0){
                        if(n % k == 0){
                                res += 1;
                                n /= k;
                        } else{
                                res += n % k;
                                n -= n % k;
                        }
                }
                cout << res << "\n";
        }
}