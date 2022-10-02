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
#include <cassert>
 
  
  
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
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}
  
inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
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
  
inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}
  
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int m;
int a, b, c;
vector<int> v[2];


int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int val;
        string t;
        cin >> val >> t;
        if (t == "USB") {
            v[0].push_back(val);
        } else {
            v[1].push_back(val);
        }
    }
    sort(all(v[0]));
    reverse(all(v[0]));
    sort(all(v[1]));
    reverse(all(v[1]));
    long long sum = 0LL;
    int cnt = 0;
    while (sz(v[0]) > 0 && a > 0) {
        a--;
        cnt++;
        sum += v[0].back();
        v[0].pop_back();
    }
    while (sz(v[1]) > 0 && b > 0) {
        b--;
        cnt++;
        sum += v[1].back();
        v[1].pop_back();
    }
    multiset<int> s;
    for (auto x: v[0]) {
        s.insert(x);
    }
    for (auto x: v[1]) {
        s.insert(x);
    }
    while (!s.empty() && c > 0) {
        cnt++;
        c--;
        int d = *s.begin();
        s.erase(s.find(d));
        sum += d;
    }
    cout << cnt << ' ' << sum << endl;
    return 0;   
}