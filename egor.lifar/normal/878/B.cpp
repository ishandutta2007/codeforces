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
const int MAXN = 200001;


int n, k, m;
int a[MAXN];    


int main() {
    n = readInt(), k = readInt(), m = readInt();
    vector<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        if (!st.empty()) {
            if (st.back().second == k) {
                st.pop_back();
            }
        }
        if (st.empty() || st.back().first != a[i]) {
            st.push_back(make_pair(a[i], 1));
        } else {
            st.back().second++;
        }
    }
    if (!st.empty()) {
        if (st.back().second == k) {
            st.pop_back();
        }
    }
    if (st.empty()) {
        writeInt(0, '\n');
        return 0;
    }
    n = sz(st);
    if (m == 1) {
        int res = 0;
        for (auto x: st) {
            res += x.second;
        }
        writeInt(res, '\n');
        return 0;
    }
    vector<pair<int, int> > mid, beg, en;
    beg = st;
    en = st;
    reverse(all(en));
    if (m != 2) {
        mid = st;
    }
    if (m == 2) {
        while (!beg.empty() && beg.back().first == en.back().first) {
            if (beg.back().second + en.back().second > k) {
                int ss = (beg.back().second + en.back().second) % k;
                beg.pop_back();
                en.back().second = ss;
                continue;
            } else {
                if (beg.back().second + en.back().second == k) {
                    beg.pop_back();
                    en.pop_back();
                    continue;
                }
            }
            break;
        }
        int res = 0;
        for (auto x: beg) {
            res += x.second;
        }
         for (auto x: en) {
            res += x.second;
        }
        writeInt(res, '\n');
    } else {
        int l = 0;
        int r = n - 1;
        while (true) {
            if (l > r) {
                break;
            }
            if (mid[l].first != beg.back().first) {
                break;
            }
            if (l == r) {
                if (1LL * mid[l].second * (m - 2) + beg.back().second + en.back().second < k) {
                    break;
                }
                int len = (1LL * mid[l].second * (m - 2) + beg.back().second + en.back().second) % k;
                l++;
                r--;
                int sss = beg.back().first;
                beg.pop_back();
                en.pop_back();
                if (len) {
                    beg.push_back(make_pair(sss, len));
                }
                break;
            }
            if (mid[l].second + beg.back().second < k) {
                break;
            }
            int len = (mid[l].second + beg.back().second) % k;
            if (len == 0) {
                l++;
                r--;
                beg.pop_back();
                en.pop_back();
            } else {
                l++;
                en.pop_back();
                beg.back().second = len;
                mid[r].second = len;
                break;
            }
        }
        if (l > r) {
            while (!beg.empty() && beg.back().first == en.back().first) {
                if (beg.back().second + en.back().second > k) {
                    int ss = (beg.back().second + en.back().second) % k;
                    beg.pop_back();
                    en.back().second = ss;
                    continue;
                } else {
                    if (beg.back().second + en.back().second == k) {
                        beg.pop_back();
                        en.pop_back();
                        continue;
                    }
                }
                break;
            }
        }
        long long res = 0;
        for (auto x: beg) {
            res += x.second;
        }
         for (auto x: en) {
            res += x.second;
        }
        for (int i = l; i <= r; i++) {
            res += 1LL * (m - 2) * mid[i].second;
        }
        cout << res << '\n';
    }
    return 0;
}