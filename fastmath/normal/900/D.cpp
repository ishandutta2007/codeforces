#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

const int MAXP = 15;
int dp[1 << MAXP];

int f(int a, int b){
    if (b == 0) return 1;
    int p = f(a, b / 2);

    if (b % 2 == 0){
        return (p * p) % MOD;
    }
    else{
        return (((p * p) % MOD) * a) % MOD;
    }
}

int get(int n){
    return f(2, n - 1);
}

vector <int> get_p(int n){
    vector <int> res;
    int d = 2;
    while (d * d <= n){
        if (n % d == 0){
            res.push_back(d);
            while (n % d == 0){
                n /= d;
            }
        }
        ++d;
    }

    if (n != 1) res.push_back(n);
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int x, y;
    cin >> x >> y;

    if (y % x){
        cout << "0\n";
        return 0;
    }
    else{
        int n = y / x;
        vector <int> p = get_p(n);
        int len = p.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << len); ++mask){
            int counter = 0;
            int fact = 1;
            for (int i = 0; i < len; ++i){
                if ((mask >> i) & 1){
                    counter++;
                    fact *= p[i];
                }
            }

            int val = get(n / fact);
            if (counter % 2 == 0){
                ans += val;
            }
            else{
                ans -= val;
            }

            ans %= MOD;
        }

        cout << (ans + MOD) % MOD;
    }

    return 0;
}