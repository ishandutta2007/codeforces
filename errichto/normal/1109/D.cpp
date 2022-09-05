#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int mod = 1e9 + 7;
const int nax = 2e6 + 5;
int fac[nax], inv_fac[nax];
int mul(int a, int b) {
    return (ll) a * b % mod;
}
int my_pow(int a, int b) {
    int r = 1;
    while(b) {
        if(b % 2) {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}
int my_inv(int a) {
    return my_pow(a, mod - 2);
}

int binomial(int a, int b) {
    if(a < b || b < 0 || a < 0) {
        return 0;
    }
    return mul(fac[a], mul(inv_fac[b], inv_fac[a-b])); //(mul(fac[b], fac[a-b])));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fac[0] = inv_fac[0] = 1;
    for(int i = 1; i <= max(n, m); ++i) {
        fac[i] = mul(fac[i-1], i);
        inv_fac[i] = my_inv(fac[i]);
    }
    int answer = 0;
    //~ int binomial = 1;
    for(int dist = 1; dist <= min(n - 1, m); ++dist) {
        int bin = binomial(m - 1, dist - 1); // krawedzie sciezki
        debug() << imie(dist) imie(bin);
        int cur = n - dist;
        int x = mul(bin, mul(my_pow(m, n - 1 - dist), mul(binomial(n - 2, dist - 1), fac[dist - 1])));
        x = mul(x, my_pow(cur - 1, cur - 1));
        int z = mul(dist + 1, my_inv(cur - 1));
        x = mul(x, z);
        answer = (answer + mul(x, my_pow(z + 1, cur - 2))) % mod;
        if(0) for(int deg = 0; deg <= cur - 2; ++deg) {
            int tmp = binomial(cur - 2, deg); // niektore liczby kodu Prufera
            
            tmp = mul(tmp, my_pow(z, deg));
            
            if(0) tmp = mul(tmp, my_pow(dist + 1, deg)); // dla kazdej krawedzi wybieramy do kogo jest podczepiony
            //~ tmp = mul(tmp, my_pow(m, n - 1 - dist)); // wszystkim pozostalym krawedziom wybieramy dlugosci
            if(0) tmp = mul(tmp, my_pow(cur - 1, cur - 2 - (deg - 1))); // pozostale elementy kodu Prufera
            //~ tmp = mul(tmp, binomial(n - 2, dist - 1)); // wybranie ziomkow do sciezki
            //~ tmp = mul(tmp, fac[dist - 1]); // kolejnosc na sciezce
            debug() << imie(dist) imie(cur) imie(deg) imie(bin) imie(tmp);
            answer = (answer + mul(tmp, x)) % mod;
        }
        if(dist == n - 1) {
            //~ int deg = 0;
            int tmp = fac[n - 2];
            //~ int tmp = binomial(cur - 2, deg - 1); // niektore liczby kodu Prufera
            //~ tmp = mul(tmp, my_pow(dist + 1, deg)); // dla kazdej krawedzi wybieramy do kogo jest podczepiony
            //~ tmp = mul(tmp, my_pow(m, n - 1 - dist)); // wszystkim pozostalym krawedziom wybieramy dlugosci
            //~ tmp = mul(tmp, my_pow(cur - 1, cur - 2 - (deg - 1))); // pozostale elementy kodu Prufera
            //~ tmp = mul(tmp, binomial(n - 2, dist - 1)); // wybranie ziomkow do sciezki
            //~ tmp = mul(tmp, fac[dist - 1]); // kolejnosc na sciezce
            //~ debug() << imie(dist) imie(cur) imie(deg) imie(bin) imie(tmp);
            answer = (answer + mul(tmp, bin)) % mod;
        }
        //~ binomial = mul(binomial, mul(m - dist, my_inv(dist)));
    }
    printf("%d\n", answer);
}