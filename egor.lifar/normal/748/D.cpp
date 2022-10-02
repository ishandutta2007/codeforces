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
  

#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int n, k;
map<string, vector<pair<int, int> > > f;
map<string, int> pos;
vector<pair<int, string> > v;
int nx[200011];
bool u[200011];



bool isPallindrom(string a) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            return 0;
        }
    }
    return 1;
} 


int main(){
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        int a;
        string s;
        cin >> s >> a;
        v.push_back(make_pair(a, s));
    }   
    int ans = 0;
    sort(all(v));
    for (int i = k - 1; i >= 0; i--) {
        int a = v[i].first;
        string s = v[i].second;
        if (pos[s] < sz(f[s])) {
            int cnt = f[s][pos[s]].first, id = f[s][pos[s]].second;
            if (cnt + a > 0) {
                nx[id] = a;
                nx[i] = cnt;
                ans += cnt + a;
                u[i] = u[id] = 1;
                pos[s]++;
            }
        } else {
            reverse(all(s));
            f[s].push_back(make_pair(a, i));
        }
    }
    int prib = 0;
    for (int i = 0; i < k; i++) {
        if (!isPallindrom(v[i].second)) {
            continue;
        }
        if (u[i]) {
            prib = max(prib, -nx[i]);
        } else {
            prib = max(prib, v[i].first);
        }
    }
    cout << ans + prib << '\n';
    return 0;
}