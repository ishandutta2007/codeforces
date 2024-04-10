#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 222;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long p, q;
                cin >> p >> q;
                long long res = 1;
                auto make = [&](long long i)
                {
                        int B = 0;
                        while(q % i == 0){
                                B += 1;
                                q /= i;
                        }
                        int A = 0;
                        long long x = 1;
                        while((p / x) % i == 0){
                                x *= i;
                                A += 1;
                        }
                        x = 1;
                        while(A > B - 1){
                                A -= 1;
                                x *= i;
                        }
                        res = max(res, p / x);
                };
                for(long long i = 2; i * i <= q; i++){
                        if(q % i){
                                continue;
                        }
                        make(i);
                }
                if(q > 1){
                        make(q);
                }
                cout << res << "\n";
        }
}