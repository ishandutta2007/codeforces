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
#include <random>
    
     
     
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


int n, start, x;
mt19937 mt(283827);


int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> start >> x;
    vector<pair<pair<int, int>, int> > kekos;
    int cnts = 0;
    cnts++;
     assert(cnts <= 1999);
     // assert(start >= 1 && start <= n);
    cout << '?' << ' ' << start << endl;
    cout.flush();
    int val, next;
    cin >> val >> next;
      // assert(val != -1);
    if (val >= x) {
        cout << '!' << ' ' << val << endl;
        cout.flush();
        return 0;
    } 
    kekos.push_back(make_pair(make_pair(val, next), start));
    set<int> was;
    was.insert(start);
    for (int i = 0; i < 1200; i++) {
        if (sz(was) == n) {
            break;
        }
        int t = mt() % n + 1;
        while (was.find(t) != was.end()) {
            t = mt() % n + 1;
        }
        was.insert(t);
        cnts++;
         assert(cnts <= 1999);
         //assert(t >= 1 && t <= n);
        cout << '?' << ' ' << t << endl;
        cout.flush();
        cin >> val >> next;
          // assert(val != -1);
        kekos.push_back(make_pair(make_pair(val, next), t));
    }
    sort(all(kekos));
    if (kekos.back().first.first < x) {
        int cur = kekos.back().first.second;
        start = cur;
        while (start != -1) {
            cnts++;
             assert(cnts <= 1999);
             // assert(start >= 1 && start <= n);
            cout << '?' << ' ' << start << endl;
            cout.flush();
            cin >> val >> next;
              // assert(val != -1);
            if (val >= x) {
                // assert(cnts < 2000);
                cout << '!' << ' ' << val << endl;
                cout.flush();
                return 0;
            }
            start = next;
        }
        if (start == -1) {
             // assert(cnts < 2000);
            cout << '!' << ' ' << -1 << endl;
            cout.flush();
            return 0;
        }
        return 0;
    }
    for (int i = 0; i < sz(kekos); i++) {
        if (kekos[i].first.first >= x) {
            if (i == 0) {
                 // assert(cnts < 2000);
                cout << '!' << ' ' << kekos[i].first.first << endl;
                cout.flush();
                return 0;
            }
            start = kekos[i - 1].first.second;
            while (start != -1) {
                if (start == kekos[i].second) {
                    // assert(cnts < 2000);
                    cout << '!' << ' ' << kekos[i].first.first << endl;
                    cout.flush();
                    return 0;
                }
                cnts++;
                assert(cnts <= 1999);
                // assert(start >= 1 && start <= n);
                cout << '?' << ' ' << start << endl;
                cout.flush();
                cin >> val >> next;
                // assert(val != -1);
                if (val >= x) {
                     // assert(cnts < 2000);
                    cout << '!' << ' ' << val << endl;
                    cout.flush();
                    return 0;
                }
                start = next;
            }
            if (start == -1) {
                 // assert(cnts < 2000);
                cout << '!' << ' ' << -1 << endl;
                cout.flush();
                return 0;
            }
            return 0;
        }
    }
   // assert(false);
    cout << '!' << ' ' << -1 << endl;
	return 0;
}