#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <uint MD> struct ModInt {
    using M = ModInt;
    static constexpr uint get_mod() { return MD; }
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using Mint = ModInt<998244353>;

int cnt[17][13];
Mint poss[17][65536];
Mint ans[17][65536];
Mint fac[65540];
Mint ifac[65540];
Mint possin[17][17][2][16];

void transform(Mint *from, Mint *to) 
{ 
    if(to - from == 1) 
        return; 
    Mint *mid = from + (to - from) / 2; 
    transform(from, mid); 
    transform(mid, to); 
    for(int i = 0; i < mid - from; i++) 
    {
        Mint a = *(from + i);
        Mint b = *(mid + i);
        *(from + i) = a + b;
        *(mid + i) = a - b;
    }
} 

Mint C(int n, int k) {
    return fac[n] * ifac[n-k] * ifac[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i <= 65536; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1] * Mint(i).inv();
    }
    
    int n, k, oc; cin >> n >> k >> oc;

    int c = max(oc, 4);
    int allx = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        allx ^= a;

        int low = a & 15;
        int high = (a >> 4);
        int highbit = (high == 0 ? c-4 : __builtin_ctz(high));

        cnt[low][highbit]++;
    }

    ans[0][0] = 1;
    for (int j = 0; j <= 16; j++) {
        transform(ans[j], ans[j]+(1<<(c-1)));
    }

    Mint invc = Mint(1<<(c-1)).inv();
    for (int low = 0; low < 16; low++) {
        for (int highbit = 0; highbit <= c-4; highbit++) if (cnt[low][highbit]) {
            
            memset(possin,0,sizeof(possin));
            memset(poss,0,sizeof(poss));

            possin[0][0][0][0] = 1;

            for (int guy = 1; guy <= min(k, cnt[low][highbit]); guy++) {
                for (int moves = 1; moves <= k+1-guy; moves++) {
                    for (int prevm = guy-1; prevm+moves <= k; prevm++) {
                        for (int prevxi = 0; prevxi <= 1; prevxi++) {
                            for (int prevxl = 0; prevxl < 16; prevxl++) {
                                if (possin[guy-1][prevm][prevxi][prevxl].v) {
                                    int xi = moves > low;
                                    int xl = ( ( ((1<<20)+low) - moves) & 15) ^ low;
                                    possin[guy][prevm+moves][prevxi ^ xi][prevxl ^ xl] += possin[guy-1][prevm][prevxi][prevxl] * C(prevm+moves,moves);
                                }
                            }
                        }
                    }
                }
            }

            int xix = ((1<<(highbit+1)) - 1) << 4;
            for (int guy = 1; guy <= min(k, cnt[low][highbit]); guy++) {
                for (int moves = guy; moves <= k; moves++) {
                    for (int prevxi = 0; prevxi <= 1; prevxi++) {
                        if (prevxi == 1 && moves <= low) continue;
                        for (int prevxl = 0; prevxl < 16; prevxl++) {
                            poss[moves][(prevxl ^ (prevxi ? xix : 0)) >> 1] += possin[guy][moves][prevxi][prevxl] * C(cnt[low][highbit], guy);
                        }
                    }
                }
            }

            for (int moves = 1; moves <= k; moves++) {
                transform(poss[moves], poss[moves] + (1<<(c-1)));
            }

            for (int tot = k; tot >= 1; tot--) {
                for (int moves = 1; moves <= tot; moves++) {        
                   for (int i = 0; i < (1<<(c-1)); i++) {
                        ans[tot][i] += ans[tot-moves][i] * poss[moves][i] * C(tot,moves);
                    }
                }
            }
        }
    }

    Mint denom = 1;
    Mint invn = Mint(n).inv();
    for (int i = 0; i < k; i++) {
        denom *= invn;
    }

    transform(ans[k], ans[k]+(1<<(c-1)));

    for (int i = 0; i < (1<<oc); i++) {
        if ((i&1) == ((allx&1) ^ (k&1))) {
            cout << ans[k][(i>>1) ^ (allx>>1)] * denom * invc << " ";
        }
        else cout << 0 << " ";
    }
    cout << endl;

    return 0;
}