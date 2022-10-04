#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

/*
const int LG = 61, N = 8;
int dp[LG][N];
int ad[N];

    const int MOD = 1e9+7;

int solve(ll n) {
        auto rel = [&] (int &a, int b) {
            a += b;
            if (a >= MOD)
                a -= MOD;
            if (a < 0)
                a += MOD;
        };  
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int bit = 0; bit < 60; ++bit) {
            memset(ad, 0, sizeof ad);
            int v = (n >> bit) & 1;
            for (int i = 0; i < N; ++i) {
                if (dp[bit][i]) {
                    int x = dp[bit][i];
                    int l = i - v + ((i ^ v) & 1);
                    int r = l + 6;
                    rel(ad[l/2], x);
                    rel(ad[r/2+1], -x);
                }   
            }   
            for (int i = 0; i < N; ++i) {
                if (i)
                    rel(ad[i], ad[i - 1]);
                dp[bit + 1][i] = ad[i];
            }   
        }   
        return dp[60][0];
}
*/

const int MOD= 1e9+7;

//need define int long long
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

struct M {
ll x;
M (int x_) {
    x = mod(x_);
}   
M () {
    x = 0;
}
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= MOD)
        ans -= MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += MOD;
    return M(ans);            
}   
M operator * (M y) {
    return M(x * y.x % MOD);   
}   
M operator / (M y) {
    return M(x * fp(y.x, MOD - 2) % MOD);
}   
M operator + (int y) {
    return (*this) + M(y);
}
M operator - (int y) {
    return (*this) - M(y);
}   
M operator * (int y) {
    return (*this) * M(y);
}   
M operator / (int y) {
    return (*this) / M(y);
}   
M operator ^ (int p) {
    return M(fp(x, p));
}   
void operator += (M y) {
    *this = *this + y;
}   
void operator -= (M y) {
    *this = *this - y;
}   
void operator *= (M y) {
    *this = *this * y;
}
void operator /= (M y) {
    *this = *this / y;
}   
void operator += (int y) {
    *this = *this + y;
}   
void operator -= (int y) {
    *this = *this - y;
}   
void operator *= (int y) {
    *this = *this * y;
}
void operator /= (int y) {
    *this = *this / y;
}   
void operator ^= (int p) {
    *this = *this ^ p;
}
};  

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;

    auto f = [&] (int n) {
        return M(n/2)*M((n+1)/2);
    };  

    while (t--) {
        int n;
        cin >> n;
        cout << f(2+n/2).x << endl;
    }   
}