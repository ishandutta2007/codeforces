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
#define ends ends228
#define begins begins228
const int MAXN = 100001;


int n;
string name[MAXN], type[MAXN];
bool used[MAXN];
bool good[MAXN];
bool inuse[MAXN * 10];
int uks;
vector<pair<string, string> > ans;



inline void adds(string a, string b) {
    ans.push_back(make_pair(a, b));
}


inline string getstr(int a) {
    string s;
    while (a > 0) {
        s += char('0' + a % 10);
        a /= 10;
    }
    reverse(all(s));
    return s;
}


inline string getrash() {
    while (inuse[uks]) {
        uks++;
    }
    assert(uks < 1000000);
    int heh = uks;
    string a;
    for (int i = 0; i < 6; i++) {
        a += char(heh % 10 + '0');
        heh /= 10;
    }
    reverse(all(a));
    uks++;
    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> type[i];
        if (type[i] == "1") {
            cnt++;
        }
    }
    uks = n + 1;
    set<int> st, st1;
    for (int i = 1; i <= cnt; i++) {
        st.insert(i);
    }
    for (int i = cnt + 1; i <= n; i++) {
        st1.insert(i);
    }
    vector<int> g, g1, h, h1, w, w1;
    for (int i = 0; i < n; i++) {
        if (type[i] == "0") {
            if (sz(name[i]) <= 6 && name[i][0] != '0') {
                int f = 0;
                bool bad = 0;
                for (int j = 0; j < sz(name[i]); j++) {
                    if (name[i][j] < '0' || name[i][j] > '9') {
                        bad = true;
                        break;
                    } 
                    f *= 10;
                    f += name[i][j] - '0';
                }
                if (!bad) {
                    inuse[f] = true;
                    if (f > cnt && f <= n && !used[f]) {
                        used[f] = true;
                        good[i] = true;
                        st1.erase(f);
                        continue;
                    }
                } 
            }
        } else { 
            if (sz(name[i]) <= 6 && name[i][0] != '0') {
                int f = 0;
                bool bad = 0;
                for (int j = 0; j < sz(name[i]); j++) {
                    if (name[i][j] < '0' || name[i][j] > '9') {
                        bad = true;
                        break;
                    } 
                    f *= 10;
                    f += name[i][j] - '0';
                }
                if (!bad) {
                    inuse[f] = true;
                    if (f <= cnt && f > 0 && !used[f]) {
                        used[f] = true;
                        good[i] = true;
                        st.erase(f);
                        continue;
                    }
                } 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            continue;
        }
        if (type[i] == "0") {
            if (sz(name[i]) <= 6 && name[i][0] != '0') {
                int f = 0;
                bool bad = 0;
                for (int j = 0; j < sz(name[i]); j++) {
                    if (name[i][j] < '0' || name[i][j] > '9') {
                        bad = true;
                        break;
                    } 
                    f *= 10;
                    f += name[i][j] - '0';
                }
                if (!bad) {
                    inuse[f] = true;
                    if (f <= cnt && f > 0 && !used[f]) {
                        used[f] = true;
                        h.push_back(i);
                        w.push_back(f);
                        st.erase(f); 
                    } else {
                        h1.push_back(i);
                    }
                } else {
                    h1.push_back(i);
                }
            } else {
                h1.push_back(i);
            }
        } else {
            if (sz(name[i]) <= 6 && name[i][0] != '0') {
                int f = 0;
                bool bad = 0;
                for (int j = 0; j < sz(name[i]); j++) {
                    if (name[i][j] < '0' || name[i][j] > '9') {
                        bad = true;
                        break;
                    } 
                    f *= 10;
                    f += name[i][j] - '0';
                }
                if (!bad) {
                    inuse[f] = true;
                    if (f <= n && f > 0 && !used[f]) {
                        used[f] = true;
                        g.push_back(i);
                        w1.push_back(f);
                        st1.erase(f);
                    } else {
                        g1.push_back(i);
                    }
                }  else {
                    g1.push_back(i);
                }
            } else {
                g1.push_back(i);
            }
        }
    }
    //cout << sz(g) << ' ' << sz(w1) << endl;
  //  return 0;
    string trash;
    while (true) {
        if (!st.empty()) {
            if (!g.empty()) {
                int sts = *st.begin();
                adds(name[g.back()], getstr(sts));
                st.erase(sts);
                st1.insert(w1.back());
                w1.pop_back();
                g.pop_back();
            } else {
                int sts = *st.begin();
                adds(name[g1.back()], getstr(sts));
                st.erase(sts);
                g1.pop_back();
            }
            continue;
        }
        if (!st1.empty()) {
            if (!h.empty()) {
                int sts = *st1.begin();
                adds(name[h.back()], getstr(sts));
                st1.erase(sts);
                st.insert(w.back());
                w.pop_back();
                h.pop_back();
            } else {
                int sts = *st1.begin();
                adds(name[h1.back()], getstr(sts));
                st1.erase(sts);
                h1.pop_back();
            }
            continue;
        }
        if (!g.empty()) {
            string f = getrash();
            adds(name[g.back()], f);
            name[g.back()] = f;
            st1.insert(w1.back());
            w1.pop_back();
            g1.push_back(g.back());
            g.pop_back();
            continue;
        }
        if (!h.empty()) {
            string f = getrash();
            adds(name[h.back()], f);
            name[h.back()] = f;
            st.insert(w.back());
            w.pop_back();
            h1.push_back(h.back());
            h.pop_back();
            continue;
        }
        break;
    } 
    assert(sz(g) == 0 && sz(g1) == 0 && sz(h) == 0 && sz(h1) == 0);  
    cout << sz(ans) << '\n';
    for (auto x: ans) {
        cout << "move" << ' ' << x.first << ' ' << x.second << '\n';
    }
    return 0;
}