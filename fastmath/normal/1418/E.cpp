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

const int N = 2e5+7, MOD = 998244353 ;
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

M f[N], inv[N];
void prec() {
    f[0] = M(1);
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * M(i);
    inv[N - 1] = f[N - 1] ^ (MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        inv[i] = inv[i + 1] * M(i + 1);
}
M C(int n, int k) {
    if (n < k)
        return M(0);
    else
        return f[n] * inv[k] * inv[n - k];
}   


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }   

    struct Quer {
        int a, b, i;
    };

    vector <M> ans(m);
    vector <Quer> da(m);
    for (int i = 0; i < m; ++i) {
        cin >> da[i].a >> da[i].b;
        da[i].i = i;
    }   

    auto comp = [&] (Quer a, Quer b) {
        return a.b > b.b;
    };  

    sort(all(da), comp);

    sort(all(d));
    reverse(all(d));

    int ptr = 0;
    M L = 0, R = 0;
    for (auto e : d)
        R += e;

    int k = 0;
    for (auto e : da) {
        while (ptr < n && d[ptr] >= e.b) {
            L += d[ptr];
            R -= d[ptr];
            k++;
            ptr++;            
        }   

        if (k < e.a) {
            ans[e.i] = M(0);
        }   
        else {
            ans[e.i] = L * M(k - e.a) / k + R * M(k + 1 - e.a) / (k + 1);
        }   
    }   

    /*
    while (m--) {
        int a, b;
        cin >> a >> b;

        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] >= b) {
                k++;
            }   
        }   

        if (k < a) {
            cout << 0 << endl;
        }   
        else {
            M ans;
            for (int i = 0; i < n; ++i) {
                if (d[i] >= b) {
                    ans += M(d[i]) * M(k - a) / k;
                }   
                else {
                    ans += M(d[i]) * M(k + 1 - a) / (k + 1);
                }   
            }
            cout << ans.x << endl;
        }   
    }
    */

    for (auto e : ans)
        cout << e.x << endl;
}