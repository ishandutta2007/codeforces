#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
    //////////// is_iterable
    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
    // this gets used only when we can call begin() and end() on that type
    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

    //////////// is_readable
    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;

    //////////// is_printable
    // // https://nafe.es/posts/2020-02-29-is-printable/
    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); // pairs

    // re: read
    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

    // rv: resize and read vectors
    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    // dumb shortcuts to read in ints
    void decrement() {} // subtract one from each
    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    // ts: string representation to print
    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } // default
    tcT> str bit_vec(T t) { // bit vector to string
        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
    tcTU> str ts(pair<T,U> p); // pairs
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        // convert container to string w/ separator sep
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    // for nested DS
    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
      ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    // print w/ no spaces
    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    // print w/ spaces, end with newline
    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    // debug to cerr
    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void dbgl_out(const T& t) {
        cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
    #ifdef LOCAL
        #define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
        #define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
    #else // don't actually submit with this
        #define dbg(...) 0
        #define dbgl(lev,x) 0
    #endif

    const clock_t beg = clock();
    #define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
        // cin.exceptions(cin.failbit);
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
    }
}

/**
 * Description: modular arithmetic operations 
 * Source: 
    * KACTL
    * https://codeforces.com/blog/entry/63903
    * https://codeforces.com/contest/1261/submission/65632855 (tourist)
    * https://codeforces.com/contest/1264/submission/66344993 (ksun)
    * also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
    * https://open.kattis.com/problems/modulararithmetic
 */

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend void re(mint& a) { ll x; re(x); a = mint(x); }
    friend str ts(mint a) { return ts(a.v); }
   
    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = int((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FOR(i,1,SZ) F0R(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: Multiply polynomials of ints for any modulus $<2^{31}$. 
     * For XOR convolution ignore \texttt{m} within \texttt{fft}. 
 * Time: O(N\log N)
 * Source: 
     * KACTL (https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/NumberTheoreticTransform.h)
     * https://cp-algorithms.com/algebra/fft.html
     * https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
     * maroonrk
     * https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp
 * Verification: 
    * https://judge.yosupo.jp/problem/convolution_mod
    * SPOJ polymul, CSA manhattan, CF Perfect Encoding
    * http://codeforces.com/contest/632/problem/E
 */

// const int MOD = 998244353;
tcT> void fft(V<T>& A, bool inv = 0) { // NTT
    int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
    for(int b = n/2; b; b /= 2, swap(A,B)) { // w = n/b'th root
        T w = pow(T::rt(),(T::mod-1)/n*b), m = 1; 
        for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
            T u = A[i+j], v = A[i+j+b]*m;
            B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
        }
    }
    if (inv) { reverse(1+all(A)); 
        T z = T(1)/T(n); each(t,A) t *= z; }
} // for NTT-able moduli
tcT> V<T> mul(V<T> A, V<T> B) {
    if (!min(sz(A),sz(B))) return {};
    int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
    bool eq = A == B; A.rsz(n), fft(A);
    if (eq) B = A; // squaring A, reuse result
    else B.rsz(n), fft(B);
    F0R(i,n) A[i] *= B[i];
    fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
    auto con = [](const V<T>& v) {
        V<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
        return w; };
    return mul(con(x),con(y));
} // arbitrary moduli
tcT> V<T> MUL(const V<T>& A, const V<T>& B) {
    using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
    using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
    using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
    int n = sz(c0); V<T> res(n); m1 r01 = 1/m1(m0::mod); 
    m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
    F0R(i,n) { // a=remainder mod m0::mod, b fixes it mod m1::mod
        int a = c0[i].v, b = ((c1[i]-a)*r01).v, 
            c = (((c2[i]-a)*r02-b)*r12).v;
        res[i] = (T(c)*m1::mod+b)*m0::mod+a; // c fixes m2::mod
    }
    return res;
}


const int mx = 400005;

struct Eff{

ll n, m;
int k;
ll a[mx]{};
ll csum[mx]{};

vi addZeroBef(vi A){
    vi res;
    res.pb(0);
    for(auto u: A){
        res.pb(u);
    }
    return res;
}

// mi oneSub(vi vals, ll B){ //naive solution on vals
//     vals = addZeroBef(vals);
//     vi val_csum = vals;
//     for(int i = 1; i < sz(val_csum); i++){
//         val_csum[i]+=val_csum[i-1];
//         val_csum[i] %= k;
//     }

//     mi res = mi(0);

//     for(int i = 1; i < sz(val_csum); i++){
//         for(int j = i; j < sz(val_csum); j++){
//             if((val_csum[j]-val_csum[i-1]+k) % k == B){
//                 res+=mi(1);
//             }
//         }
//     }
//     // dbg(val_csum, res);
//     return res;
// }

mi oneSub(vi vals, ll B){ //good solution on vals
    vals = addZeroBef(vals);
    vi val_csum = vals;
    for(int i = 1; i < sz(val_csum); i++){
        val_csum[i]+=val_csum[i-1];
        val_csum[i] %= k;
    }

    mi res = mi(0);

    vmi rems(k, mi(0));
    for(int i = 0; i < sz(val_csum); i++){
        int need = (-B+val_csum[i]+k) % k;
        res+=rems[need];
        rems[val_csum[i]]+=mi(1);
    }
    // dbg(val_csum, res);
    return res;
}



// vmi sufPref(){
//     vmi res(k, mi(0));

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             ll pref = csum[i];
//             ll suf = (csum[n]-csum[j-1]+k) % k;
//             res[(pref+suf) % k]+=mi(1);
//         }
//     }
//     return res;
// }

vmi sufPref(){
    vmi poly1 = vmi(k, mi(0));
    for(int i = 1; i <= n; i++){
        ll pref = csum[i];
        assert(0 <= pref && pref < k);
        poly1[pref]+=mi(1);
    }

    vmi poly2 = vmi(k, mi(0));

    for(int i = 1; i <= n; i++){
        ll suf = (csum[n]-csum[i-1]+k) % k;
        assert(0 <= suf && suf < k);
        poly2[suf]+=mi(1);
    }

    // dbg(poly1, poly2);
    // vmi res = poly1*poly2;
    // vmi res = vmi(k, mi(0));

    dbg("BEGIN FFT");
    vmi res = MUL(poly1, poly2);
    dbg("END FFT");

    vmi resk = vmi(k, mi(0));
    for(int i = 0; i < sz(res); i++){
        resk[i % k]+=res[i];
    }
    return resk;
}

vector<ll> calc(ll m, ll k) {
    // dbg("BEGIN CALC");
    m--;
    vector<ll> res(k, 0);
    for (int i = 0; i < k; ++i) {
        ll cnt = m - i;
        if (cnt <= 0) {
            continue;
        }
        ll full_blocks = cnt / k;
        res[i] = full_blocks * (full_blocks + 1) / 2 * k;
        res[i] += (full_blocks + 1) * (cnt % k);
    }
    // dbg("END CALC");
    return res;
}

vmi getIJ(){
    vl RES = calc(m, k);
    assert(sz(RES) == k);
    vmi res;
    for(auto u: RES){
        res.pb(mi(u));
    }
    return res;
}

// vmi getIJ(){
//     vmi res(k, mi(0));
//     for(int i = 1; i <= m-1; i++){
//         for(int j = i; j <= m-1; j++){ //m, k = 2*10^5
//             res[(j-i) % k]+=mi(1);
//         }
//     }
//     assert(res == getIJFast());
//     return res;
// }

int getPow(ll base, ll expo){
    // dbg("BEGIN CALC");
    ll res = 1;

    while(expo > 0){
        if(expo&1LL){
            res = (res*base) % k;
        }
        expo/=2;
        base = (base*base) % k;
    }

    // dbg("END CALC");
    return (int)(res % k);
}

int getInv(int base){
    return getPow(base, k-2);
}

mi array2Sol(ll B){
    // dbg("BEGIN CALC");

    dbg(B);
    vmi rems = sufPref();
    mi ans = mi(0);
    vmi ij_diffs = getIJ();

    assert(sz(rems) == k && sz(ij_diffs) == k); 

    // dbg(ij_diffs);
    // dbg(rems);


    for(int i = 0; i < k; i++){ //contributed from suffix and prefix
        int need = (int)((B-i+k) % k); //diff*csum[n] = need

        if(csum[n] == 0){
            if(need == 0){
                ans+=rems[i]*mi((ll(m)*ll(m-1))/2); //any pair
            }
            else{
                ans+=mi(0);
            }
        }
        else{
            assert(k > 1);
            int diff = (int)((ll(getInv(csum[n]))*ll(need)) % k);

            ans+=rems[i]*ij_diffs[diff];
            assert(0 <= diff && diff < k);
        }
    }

    // dbg("END CALC");
    return ans;
}

mi getSubarrays(ll B){ //sum of subarray is b
    // dbg("BEGIN CALC");
    vi justOne;
    for(int i = 1; i <= n; i++){
        justOne.pb(a[i]);
    }
    mi ans1 = oneSub(justOne, B); ans1*=mi(m);

    
    mi ans2 = array2Sol(B);
    // exit(0);
    // return mi(0);
    // dbg(ans1, ans2);
    // dbg("END CALC");
    return ans1+ans2;
}

mi getPrefs(ll B){
    for(int i = 1; i <= n; i++){
        csum[i] = (csum[i-1]+a[i]) % k;
    }

    vmi rems(k, mi(0));
    for(int j = 1; j <= m; j++){ //contained within first j
        rems[(csum[n]*ll(j-1)) % k]+=mi(1);
    }
    // dbg(rems);
    mi res = mi(0);
    for(int i = 1; i <= n; i++){
        int need = (B-csum[i]+k) % k;
        // dbg(i, need);
        res+=rems[need];
    }
    return res;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]%=k;
    }
    for(int i = 1; i <= n; i++){
        csum[i] = (csum[i-1]+a[i]) % k;
    }

    ll tot = (ll(csum[n])*ll(m)) % k;

    mi contig1 = getSubarrays(0);
    // exit(0);
    mi contig2 = getSubarrays(tot);



    mi pref1 = getPrefs(tot);

    for(int i = 1; i <= n/2; i++){
        swap(a[i], a[n+1-i]);
    }

    mi pref2 = getPrefs(tot);

    dbg(contig1, contig2);
    dbg(pref1, pref2);
    mi ans = contig1+contig2-pref1-pref2+mi(1);



    ps(ans);
}  

};


int main() {
    setIO();
    Eff e;
    e.solve();
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/