#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600100;

using namespace std;

long long a, b, c, d;

long long get(long long A)
{
        long long t = A * d;
        long long i = 0;
        if(c <= t){
                i = (t - c) / d + 1;
        }
        long long res = a * (A + 1);
        res -= b * i * c;
        i = A - i;
        if(i > 0){
                res -= i * (i + 1) / 2 * d * b;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                cin >> a >> b >> c >> d;
                long long l = 0, r = 2e6;
                while(l < r){
                        long long m = (l + r) / 2;
                        if(get(m + 1) > get(m)){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                if(get(l + 1) > get(l)){
                        cout << -1 << "\n";
                } else{
                        cout << get(l) << "\n";
                }
        }
}