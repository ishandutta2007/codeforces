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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 100001;


long long ts, tf, t;
int n;
long long a[MAXN];
map<long long, int> cnt;

 
int main() {
    scanf("%lld %lld %lld %d", &ts, &tf, &t, &n);
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        v.push_back(a[i]);
        v.push_back(a[i] - 1);
        v.push_back(a[i] + 1);
        v.push_back(a[i] - t);
        v.push_back(a[i] - t + 1);
        v.push_back(a[i] + t);
        v.push_back(a[i] - t - 1);
        v.push_back(a[i] + t + 1);
        v.push_back(ts + t * (i + 1));
        cnt[a[i]]++;
    }
    v.push_back(ts - t);
    v.push_back(ts);
    v.push_back(ts - 1);
    v.push_back(ts + 1);
    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));
    reverse(all(v));
    while (v.back() < 0) {
        v.pop_back();
    }
    reverse(all(v));
    int cnts = 0;
    long long ans = 1e18;
    long long time = -1;
    long long last = ts;
    for (auto x: v) {
        cnts += cnt[x];
        last = max(last, x);
        if (last + t * (cnts + 1) <= tf) {
            if (ans > last + t * (cnts + 1) - x) {
                ans = last + t * (cnts + 1) - x;
                time = x;
            }
        }   
        if (cnts > 0) {
            last += cnts * t;
            cnts = 0;
        } 
        if (last >= tf) {
            break;
        }
    }
    printf("%lld\n", time);
    return 0;
}