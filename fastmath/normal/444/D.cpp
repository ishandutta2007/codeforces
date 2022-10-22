#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
using namespace std;

#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
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
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

map <string, int> num;

V <string> book;

const int N = 200007;
int big_num[N];
vi pos[N];
int cnt[N];

const int T = 1000, K = 207;

int prec[K][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    int n = s.size();

    int p = 0;
    FOR (i, n) {
        for (int len = 1; len <= 4 && i + len <= n; ++len) {
            string t = s.substr(i, len);
            int id = -1;
            if (!num.count(t)) {
                book.app(t);
                id = p;
                num[t] = p++;
            }
            else {
                id = num[t];
            }
            pos[id].app(i);
            cnt[id]++;
        }
    }

    int sz = p;
    int ptr = 0;
    FOR (word, sz) {
        if (cnt[word] >= T) {
            big_num[word] = ptr;
            int len = book[word].size();
            FOR (i, N) {
                prec[ptr][i] = n + 1;
            }
            int last = -1;
            FOR (i, n) {
                if (i + len <= n && s.substr(i, len) == book[word]) {
                    last = i;
                }
                if (last != -1) {
                    for (int l = 1; i + l <= n && l <= 4; ++l) {
                        int r = max(last + len, i + l);
                        ckmin(prec[ptr][num[s.substr(i, l)]], r - last);          
                    }                    
                }
            }
            last = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (i + len <= n && s.substr(i, len) == book[word]) {
                    last = i;
                }
                if (last != -1) {
                    for (int l = 1; i + l <= n && l <= 4; ++l) {
                        int r = max(last + len, i + l);
                        ckmin(prec[ptr][num[s.substr(i, l)]], r - i);          
                    }     
                }
            }
            ptr++;
        }
    }

    int q;
    cin >> q;
    rep (q) {
        string a, b;
        cin >> a >> b;

        if (!num.count(a) || !num.count(b)) {
            cout << -1 << endl;
            continue;
        }

        int a_id = num[a];
        int b_id = num[b];

        if (cnt[a_id] < T && cnt[b_id] < T) {
            int pa = 0, pb = 0;
            vi &A = pos[a_id];
            vi &B = pos[b_id];
            int ans = n + 1;
            while (pa < A.size() && pb < B.size()) {
                int l = min(A[pa], B[pb]);
                int r = max(A[pa] + a.size(), B[pb] + b.size());
                ckmin(ans, r - l);
                if (A[pa] < B[pb]) {
                    pa++;
                }
                else {
                    pb++;
                }
            }
            cout << ans << endl;
        }
        else if (cnt[a_id] >= T) {
            cout << prec[big_num[num[a]]][num[b]] << endl;
        }
        else {
            cout << prec[big_num[num[b]]][num[a]] << endl;
        }
    }
}