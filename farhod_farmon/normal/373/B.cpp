#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int MAGIC = sqrt(N);

using namespace std;

long long n, w, k;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> w >> n >> k;
        w /= k;

        vector < pair < long long, long long > > v;
        long long p = 9, g = 1;
        while(p < n){
                p = p * 10 + 9;
                g += 1;
        }
        v.push_back({p - n + 1, g});
        p += 1;
        g += 1;
        while(p <= (long long)1e17){
                v.push_back({p * 10 - p, g});
                p *= 10;
                g += 1;
        }

        long long res = 0;
        for(auto f: v){
                long long g = min(w / f.se, f.fi);
                res += g;
                w -= g * f.se;
        }
        cout << res << "\n";
}