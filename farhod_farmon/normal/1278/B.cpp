#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

bool can(int k, int a)
{
        for(int i = k; i >= 1; i--){
                if(abs(a + i) < abs(a - i)){
                        a += i;
                } else{
                        a -= i;
                }
        }
        return (a == 0);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long a, b;
                cin >> a >> b;
                a = abs(a - b);

                long long l = 0, r = a;
                while(l < r){
                        long long m = (l + r) / 2;
                        if(m * (m + 1) / 2 < a){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }

                while(!can(l, a)){
                        l += 1;
                }

                cout << l << "\n";
        }
}