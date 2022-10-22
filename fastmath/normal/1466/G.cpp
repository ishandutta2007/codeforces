#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
//ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
//ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}

//need define int long long
namespace Stuff {
const int MOD = 1e9+7;
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
};
struct M {
ll x;
M (int x_) { x = Stuff::mod(x_); }   
M () { x = 0; }
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= Stuff::MOD)
        ans -= Stuff::MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += Stuff::MOD;
    return M(ans);            
}   
M operator * (M y) { return M(x * y.x % Stuff::MOD); }   
M operator / (M y) { return M(x * Stuff::fp(y.x, Stuff::MOD - 2) % Stuff::MOD); }   
M operator + (int y) { return (*this) + M(y); }
M operator - (int y) { return (*this) - M(y); }   
M operator * (int y) { return (*this) * M(y); }   
M operator / (int y) { return (*this) / M(y); }   
M operator ^ (int p) { return M(Stuff::fp(x, p)); }   
void operator += (M y) { *this = *this + y; }   
void operator -= (M y) { *this = *this - y; }   
void operator *= (M y) { *this = *this * y; }
void operator /= (M y) { *this = *this / y; }   
void operator += (int y) { *this = *this + y; }   
void operator -= (int y) { *this = *this - y; }   
void operator *= (int y) { *this = *this * y; }
void operator /= (int y) { *this = *this / y; }   
void operator ^= (int p) { *this = *this ^ p; }
};  
std::ostream& operator << (std::ostream& o, const M& a)
{
    cout << a.x;
    return o;
}

vector<int> prefix_function (string s) { // pi[i] - prefix_function of s[0:i+1]
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}
int KMP(string s, string t) { //number of occurences of s in t
    int n = s.size();
    s += '#';
    s += t;
    vi p = prefix_function(s);
    int ans = 0;
    FOR (i, (int)s.size()) {
        ans += p[i] == n;
    }
    return ans;
}   
int KMP(string s, string t, int pos) { //number of occurences of s in t
    int n = s.size();
    s += '#';
    s += t;
    pos += n + 1;
    vi p = prefix_function(s);
    int ans = 0;
    FOR (i, (int)s.size()) {
        int l = i - n + 1;
        int r = i;
        if (l <= pos && pos <= r) {
            ans += p[i] == n;
        }
    }
    return ans;
}   

const int N = 1e5+7;
const int UP = 22;
string in[UP];

M pw[N];
M inv[N];

const int C = 26;
M pref[C][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * 2;

    M iv = M(1)/2;
    inv[0] = 1;
    for (int i = 1; i < N; ++i)
        inv[i] = inv[i - 1] * iv;

    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    int S = s.size();

    in[0] = s;
    FOR (i, min(n, 20ll)) {
        in[i + 1] = in[i] + t[i] + in[i];
        if (in[i + 1].size() >= 1000 * 1000)
            break;                
    }   

    FOR (c, C) {
        FOR (i, n) {
            pref[c][i + 1] = pref[c][i];
            if (t[i] - 'a' == c) {
                pref[c][i + 1] += inv[i + 1];
            }   
        }   
    }   

    while (q--) {
        int num;
        cin >> num;

        string w;
        cin >> w;
        
        int ptr = 0;
        while (ptr < UP && in[ptr].size() < w.size()) {
            ptr++;
        }   
        if (ptr == UP || num < ptr) {
            cout << 0 << endl;
            continue;
        }   

        M ans = pw[num - ptr] * KMP(w, in[ptr]);
        int sz = in[ptr].size();
        int wsz = w.size();
        for (char c = 'a'; c <= 'z'; ++c) {
            string tmp = in[ptr].substr(sz - wsz, wsz) + c + in[ptr].substr(0, wsz);
            int k = KMP(w, tmp, wsz);
            int cv = c - 'a';
            ans += (pref[cv][num] - pref[cv][ptr]) * pw[num] * k;
        }   
        cout << ans << endl;
    }   
}