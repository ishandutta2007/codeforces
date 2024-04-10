/*
  !










*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     
/** Read */
     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
     
/** Write */
     
static int write_pos = 0;
static char write_buf[buf_size];
     
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
     
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
     
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
   
   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
const int MAXN = 801;
const int Mod = 1000000007;


int a[MAXN];
vector<int> v[MAXN];
int c[MAXN];
int uk;


void dfs(int u) {
    c[u] = uk;
    for (auto x: v[u]) {
        if (!c[x]) {
            dfs(x);
        }
    }
}


int fact[MAXN + 2], inv_fact[MAXN + 2];


inline int cnk(int n, int k) {
    if (n < k) {
        swap(n, k);
    }
    return 1LL * fact[n] * inv_fact[k] % Mod * 1LL * inv_fact[n - k] % Mod;
}


inline int pow(int x, int st) {
    int result = 1;
    while (st) {
        if (st & 1) {
            result = 1LL * result * x % Mod;
        }
        x = 1LL * x * x % Mod;
        st >>= 1;
    }
    return result;
}


int Solve(vector<int> numbers) {
    int first_element = numbers[0];
    vector<int> dp(numbers[0], 0);
    dp[first_element - 1] = 1;
    for (int t = 1; t < (int)numbers.size(); t += 1) {
        int number = numbers[t];
        int num_elements = (int)dp.size();
        vector<int> next(num_elements + number, 0);
        for (int bad_adjacent = 0; bad_adjacent < num_elements; bad_adjacent += 1) {
            if (dp[bad_adjacent] == 0) {
                continue;
            }
            for (int num_splits = 1; num_splits <= min(number, 1 + num_elements); num_splits += 1) {
                for (int chosen_bad = 0; chosen_bad <= min(num_splits, bad_adjacent); chosen_bad += 1) {
                    int good_adjacent = num_elements + 1 - bad_adjacent;
                    int chosen_good = num_splits - chosen_bad;
                    if (chosen_good < 0) {
                        continue;
                    }
                    if (chosen_good > good_adjacent) {
                        continue;
                    }
                    int new_bad_adjacent = bad_adjacent - chosen_bad + (number - num_splits);
                    int num_ways = 1LL * cnk(number - 1, num_splits - 1) * cnk(good_adjacent, chosen_good) % Mod * 1LL * cnk(bad_adjacent, chosen_bad) % Mod;
                    num_ways = 1LL * num_ways * dp[bad_adjacent] % Mod;
                    next[new_bad_adjacent] += num_ways;
                    if (next[new_bad_adjacent] >= Mod) {
                        next[new_bad_adjacent] -= Mod;
                    }
                }
            }
        }
        dp = next;
    }
    return dp[0];
}


int main(){
    int n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)sqrt(1LL * a[i] * a[j]) * (long long)sqrt(1LL * a[i] * a[j]) == 1LL * a[i] * a[j]) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!c[i]) {
            uk++;
            dfs(i);
        }
    }
    unordered_map<int, int> number_cnt;
    for (int i = 0; i < n; i += 1) {
        //cout << c[i] << endl;
        number_cnt[c[i]] += 1;
    }
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= MAXN; i += 1) {
        fact[i] = 1LL * i * fact[i - 1] % Mod;
    }
    inv_fact[MAXN] = pow(fact[MAXN], Mod - 2);
    for (int i = MAXN - 1; i; i -= 1) {
        inv_fact[i] = 1LL * (i + 1) * inv_fact[i + 1] % Mod;
    }
    vector<int> numbers;
    int t = 1;
    for (auto& itr : number_cnt) {
        numbers.push_back(itr.second);
        t = (1LL * t * fact[itr.second]) % Mod;
    }
    cout << (1LL * t * Solve(numbers)) % Mod << '\n';
    return 0;
}