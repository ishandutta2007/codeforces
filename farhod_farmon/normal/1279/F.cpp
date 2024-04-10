#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int l;
int s[N];
int a[N];
string t;
pair < long long, int > d[N];

int f(char c)
{
        if('a' <= c && c <= 'z'){
                return 0;
        }
        return 1;
}

pair < long long, int > get(long long C)
{
        pair < long long, int > best = {0, 0};

        for(int i = 1; i <= n; i++){
                d[i] = {0, 0};
                if(i >= l){
                        best = max(best, d[i - l]);
                        d[i] = best;

                        d[i].fi += a[i] - C;
                        d[i].se -= 1;
                }
        }

        for(int i = n - l; i <= n; i++){
                best = max(best, d[i]);
        }

        best.se = - best.se;

        return best;
}

int solve(int need)
{
        for(int i = 1; i <= n; i++){
                s[i] = s[i - 1] + (f(t[i - 1]) == need);
                if(i >= l){
                        a[i] = s[i] - s[i - l];
                }
        }

        long long l = 0, r = 1e12;
        while(l < r){
                long long m = (l + r) / 2;
                if(get(m).se > k){
                        l = m + 1;
                } else{
                        r = m;
                }
        }

        return s[n] - (get(l).fi + 1ll * k * l);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k >> l >> t;
        if(1ll * k * l > n){
                cout << 0 << "\n";
                return 0;
        }

        cout << min(solve(0), solve(1)) << "\n";
}