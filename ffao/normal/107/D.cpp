#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <list>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <complex>

using namespace std;

#define all(a)              (a).begin(), (a).end()
#define ms(a,b)             memset(a, b, sizeof(a))
#define mp                  make_pair
#define pb                  push_back
#define fore(it,a)          for (auto it = (a).begin(), it##_ = (a).end(); it != it##_; ++it)
#define f0r(i, a)           for (int i = 0, i##_ = (a); i < i##_; ++i)
#define debug(args...)      do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define read(type, args...) type args; rdr,args;
#define fi                  first
#define se                  second
#define bit_no              __builtin_popcount
#define left(a)             (2*(a))
#define right(a)            (2*(a)+1)
#define mid(left, right)    (((left)+(right))/2+1)
#define PI                  acos(-1)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          ii;
typedef tuple<int, int, int>    iii;
typedef vector<ii>              vii;
typedef vector<iii>             viii;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int inf = 2e8+5;
const ll l_inf = 9e18+5;
const int mod_v = 12345;
const int max_n = 1e5+5;

template<typename T>
T gcd(T a, T b)
{
    while (b) {
        T temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

template<typename T>
tuple<T, T, T> egcd(T a, T b)
{
    T x1 = 1, x2 = 0, y1 = 0, y2 = 1;
    while (b) {
        T q = a / b, r = a % b;
        T new_x = x1 - q*x2, new_y = y1 - q*y2;
        x1 = x2, y1 = y2, x2 = new_x, y2 = new_y;
        a = b, b = r;
    }
    return make_tuple(a, x1, y1);
}

inline ll lcm(ll a, ll b)
{
    return a*b/gcd(a, b);
}

template<typename T>
inline T mod(T a, T b = mod_v)
{
    return (a % b + b) % b;
}

template<typename T>
inline T mod_inv(T a, T b = mod_v)
{
    return mod(get<1>(egcd(a, b)), b);
}

template<typename T>
inline T sum(T a, T b, T m = mod_v)
{
    return mod(mod(a, m) + mod(b, m), m);
}

template<typename T>
inline T difference(T a, T b, T m = mod_v)
{
    return mod(mod(a, m) - mod(b, m), m);
}

inline ll product(ll a, ll b, ll m = mod_v)
{
    return mod(mod(a, m) *  mod(b, m), m);
}

inline ll quotient(ll a, ll b, ll m = mod_v)
{
    return mod(mod(a, m) * mod_inv(b, m), m);
}

template<typename T,typename T2>
ostream& operator<< (ostream &s, const pair<T,T2> &p) {return s << p.fi << ' ' << p.se << ' ';}

template<typename T,typename T2>
istream& operator>> (istream &s, pair<T,T2> &p) {return s >> p.fi >> p.se;}

template<typename T>
ostream& operator<< (ostream &s, const vector<T> &v)  {for (auto it: v) s << it << ' '; return s;}

template<typename T>
istream& operator>> (istream &s, vector<T> &v) {fore (it, v) s >> *it; return s;}

template<typename T>
void read_range(T beg, T end)
{
    while (beg != end)
        cin >> *beg++;
}

template<typename T>
void print_range(T beg, T end)
{
    while (beg != end)
        cout << *beg++ << ' ';
}

struct reader
{
    template<typename T>
    reader& operator, (T &v)
    {
        cin >> v;
        return *this;
    }
} rdr;

struct debugger
{
    template<typename T>
    debugger& operator, (const T &v)
    {
        cerr << v << ", ";
        return *this;
    }
} dbg;

/***************************************************************
----------------------------------------------------------------
----------------------------------------------------------------
***************************************************************/

int ar[123][123];
int res[123][123];
int temp[123][123];
int mult[26];
int hash_mult[27];
vi mult2[26];

void prod(int a[][123], const int b[][123])
{
    f0r (i, hash_mult[26])
        f0r (j, hash_mult[26]) {
            temp[i][j] = 0;
            f0r (k, hash_mult[26])
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod_v;
        }
    memcpy(a, temp, sizeof(temp));
}

void power(ll p)
{
    f0r (i, hash_mult[26])
        res[i][i] = 1;
    while (p) {
        if (p & 1)
            prod(res, ar);
        prod(ar, ar);
        p >>= 1;
    }
}

void init_hash()
{
    f0r (i, 27) {
        if (i == 0) hash_mult[i] = 1;
        else hash_mult[i] = (hash_mult[i-1] * max(1, mult[i-1]));
    }
}

bool correct(int i) {
    f0r (j, 26)
        if (mult[j]) {
            int cur_cnt = (i / hash_mult[j]) % mult[j];
            bool ok = false;
            for (int m : mult2[j])
                if (cur_cnt % m == 0) ok = true;
            if (!ok) return false;
        }

    return true;
}

void init_ar()
{
    f0r (i, hash_mult[26]) {
        f0r (j, 26)
            if (mult[j]) {
                int cur_cnt = (i / hash_mult[j]) % mult[j];
                int new_cnt = (cur_cnt + 1) % mult[j];
                int new_s_no = i + (new_cnt - cur_cnt) * hash_mult[j];
                
                ar[i][new_s_no]++;
            }
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    read(ll, n); 
    read(int, c);
    
    f0r (i, c) {
        read(char, ch); 
        read(int, m);
        if (mult[ch - 'A'] == 0)
            mult[ch - 'A'] = m;
        else
            mult[ch - 'A'] = lcm(mult[ch - 'A'], m);
        mult2[ch - 'A'].pb(m);
    }
    
    init_hash();
    init_ar();
    
    power(n);

    int r = 0;
    f0r (i, hash_mult[26]) 
        if (correct(i))
            r = (r + res[0][i]) % mod_v;
    
    cout << r;

    return 0;
}