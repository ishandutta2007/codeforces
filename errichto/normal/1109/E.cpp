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

int mod;
vector<int> primes;
vector<int> expo;
int k;

int magic;

int mul(int a, int b) {
    return (ll) a * b % mod;
}
void mul_self(int& a, int b) {
    a = mul(a, b);
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
//~ int my_inv(int a) {
    //~ return my_pow(a, mod - 2);
//~ }

void factorize() {
    magic = mod;
    
    //~ for(int z = 2; z < mod; ++z) {
        //~ if(__gcd(z, mod) == 1) {
            //~ ++magic;
        //~ }
    //~ }
    int value = mod;
    for(int i = 2; i * i <= value; ++i) {
        if(value % i == 0) {
            primes.push_back(i);
            int cnt = 0;
            while(value % i == 0) {
                ++cnt;
                value /= i;
            }
            expo.push_back(cnt);
        }
    }
    if(value != 1) {
        primes.push_back(value);
        expo.push_back(1);
    }
    k = primes.size();
    for(int p : primes) {
        magic = magic / p * (p - 1);
    }
    --magic;
}

struct S {
    vector<int> cnt;
    int sum, real_extra, lazy_mul;
    void print() {
        debug() << imie(cnt) imie(sum) imie(real_extra);
    }
    void merge(const S& a, const S& b) {
        sum = a.get_real_sum() + b.get_real_sum();
        if(sum >= mod) {
            sum -= mod;
        }
        //~ real_sum = sum;
    }
    void init(int x) {
        assert(x != 0);
        //~ real_sum = x % mod;
        real_extra = 1;
        for(int i = 0; i < k; ++i) {
            while(x % primes[i] == 0) {
                x /= primes[i];
                ++cnt[i];
                real_extra = mul(real_extra, primes[i]);
            }
        }
        sum = x % mod;
    }
    int get_real_sum() const {
        return mul(sum, real_extra);
    }
    void update_real_extra() {
        real_extra = 1;
        for(int i = 0; i < k; ++i) {
            if(cnt[i]) {
                real_extra = mul(real_extra, my_pow(primes[i], cnt[i]));
            }
        }
    }
};

vector<S> tree;

vector<int> g_cnt;
int extra_x, x_magic;
void compute_g_cnt(int& x) {
    extra_x = 1;
    assert(x != 0);
    g_cnt = vector<int>(k);
    for(int i = 0; i < k; ++i) {
        while(x % primes[i] == 0) {
            ++g_cnt[i];
            x /= primes[i];
            extra_x = mul(extra_x, primes[i]);
        }
    }
    x %= mod;
}

    int pot = 1;
const int MUL = 1, DIVIDE = 2, QUERY = 3;
void rec(int id, int low, int high, int q_low, int q_high, int type, int& x) {
    if(q_high < low || high < q_low) {
        return;
    }
    if(q_low <= low && high <= q_high) {
        if(type == QUERY) {
            x = (x + tree[id].get_real_sum()) % mod;
            //~ if(x >= mod) {
                //~ x -= mod;
            //~ }
        }
        else if(type == DIVIDE) {
            for(int i = 0; i < k; ++i) {
                tree[id].cnt[i] -= g_cnt[i];
                assert(tree[id].cnt[i] >= 0);
            }
            debug() << imie(tree[id].sum) imie(x);
            tree[id].sum = mul(tree[id].sum, x_magic); //my_pow(x, magic));
            tree[id].update_real_extra();
            //~ tree[id].sum /= x; // TODO
        }
        else {
            assert(type == MUL);
            for(int i = 0; i < k; ++i) {
                tree[id].cnt[i] += g_cnt[i];
            }
            tree[id].sum = mul(tree[id].sum, x);
            //~ tree[id].update_real_sum();
            debug() << imie(extra_x);
            tree[id].real_extra = mul(tree[id].real_extra, extra_x);
            mul_self(tree[id].lazy_mul, x);
        }
        return;
    }
    
    #ifdef LOCAL
    debug() << imie(id);
    tree[id].print();
    tree[pot+1].print();
    #endif
    // propagate
    tree[id].sum = 0; // unnecessary?
    for(int i = 0; i < k; ++i) {
        tree[2*id].cnt[i] += tree[id].cnt[i];
        tree[2*id+1].cnt[i] += tree[id].cnt[i];
        tree[id].cnt[i] = 0;
    }
    for(int b : {2 * id, 2 * id + 1}) {
        tree[b].real_extra = mul(tree[b].real_extra, tree[id].real_extra);
        mul_self(tree[b].sum, tree[id].lazy_mul);
        mul_self(tree[b].lazy_mul, tree[id].lazy_mul);
    }
        //~ tree[2*id].real_extra = mul(tree[2*id].real_extra, tree[id].real_extra);
        //~ tree[2*id+1].real_extra = mul(tree[2*id+1].real_extra, tree[id].real_extra);
    tree[id].real_extra = tree[id].lazy_mul = 1;
    
    #ifdef LOCAL
    debug() << imie(id);
    tree[pot+1].print();
    #endif
    int last_left = (low + high) / 2;
    rec(2 * id, low, last_left, q_low, q_high, type, x);
    rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);
    
    tree[id].merge(tree[2*id], tree[2*id+1]);
}

int main() {
    int n;
    scanf("%d%d", &n, &mod);
    factorize();
    while(pot < n) {
        pot *= 2;
    }
    tree.resize(2 * pot, S{vector<int>(k), 0, 1, 1});
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        tree[pot+i].init(x);
    }
    for(int i = pot - 1; i >= 1; --i) {
        tree[i].merge(tree[2*i], tree[2*i+1]);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int low, high, x;
            scanf("%d%d%d", &low, &high, &x);
            //~ real_x = x % mod;
            compute_g_cnt(x);
            --low;
            --high;
            // multiply
            #ifdef LOCAL
            tree[pot+1].print();
            #endif
            //~ debug() << imie(tree[pot+1].real_sum) imie(tree[pot+1].sum) imie(real_x);
            rec(1, 0, pot - 1, low, high, type, x);
            #ifdef LOCAL
            tree[pot+1].print();
            #endif
            //~ debug() << imie(tree[pot+1].real_sum) imie(tree[pot+1].sum);
        }
        else if(type == 2) {
            int i, x;
            scanf("%d%d", &i, &x);
            compute_g_cnt(x);
            --i;
            // divide
            x_magic = my_pow(x, magic);
            rec(1, 0, pot - 1, i, i, type, x);
        }
        else {
            assert(type == 3);
            int low, high;
            scanf("%d%d", &low, &high);
            --low;
            --high;
            // query for sum
            int answer = 0;
            rec(1, 0, pot - 1, low, high, type, answer);
            printf("%d\n", answer);
        }
    }
}