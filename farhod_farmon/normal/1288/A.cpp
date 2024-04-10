#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long n, d;
                cin >> n >> d;
                long long res = n + 1;
                for(long long i = min(d, (long long)6e5); i >= 0; i--){
                        res = min(res, i + (d - 1) / (i + 1) + 1);
                }
                if(res <= n){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}