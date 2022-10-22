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

    const int C = 1000 * 100 + 7, N = C, MOD = 1e9+7;
bool kv[C];
int how[C];
bool p[C];


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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 2; i < C; ++i)
        p[i] = 1;
    for (int i = 2; i < C; ++i) {
        if (p[i]) {
            for (int j = i * 2; j < C; j += i) {
                p[j] = 0;
            }   
            for (int j = i * i; j < C; j += i * i) {
                kv[j] = 1;
            }   
            for (int j = i; j < C; j += i) {
                how[j]++;
            }
        }
    }   

    int n;
    cin >> n;
    vector <int> cnt(C);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }   
    
    M ans = 0;
    for (int d = 1; d < C; ++d) {
        if (!kv[d]) {
            int t = 0;
            for (int i = d; i < C; i += d)
                t += cnt[i];
            if (how[d] & 1)
                ans -= M(fp(2, t)) - 1;
            else
                ans += M(fp(2, t)) - 1;                
        }   
    }   
    cout << ans.x << endl;
}