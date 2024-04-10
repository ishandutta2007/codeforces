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
const int MAXN = 128;


int n;
string names[MAXN];
string ans[MAXN];
vector<string> words[MAXN];
unordered_map<string, int> who;
bool notcan[MAXN][MAXN];
vector<int> cans[MAXN];
string g[MAXN];


inline bool valid(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}


void forbid(int ii, string &s) {
    string cur;
    for (int i = 0; i < sz(s); i++) {
        if (valid(s[i])) { 
            cur += s[i];
        } else {
            if (!cur.empty()) {
                if (who.find(cur) != who.end()) {
                    notcan[ii][who[cur]] = 1;
                }
                cur.clear();
            }
        }
    }
    if (!cur.empty()) {
        if (who.find(cur) != who.end()) {
            notcan[ii][who[cur]] = 1;
        }
        cur.clear();
    }
}


char c[300];


int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d\n", &t);
    for (int ttt = 0; ttt < t; ttt++) {
        who.clear();
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++) {
            cin >> names[i];   
            who[names[i]] = i;    
        }
        int k;
        scanf("%d\n", &k);
        for (int ii = 0; ii < k; ii++) {
            ans[ii].clear();
            words[ii].clear();
            cin.getline(c, 200);
            string a = string(c);
            bool t = 1;
            string cur;
            g[ii].clear();
            for (int i = 0; i < sz(a); i++) {
                if (a[i] == ':') {
                    for (int j = 0; j < i; j++) {
                        ans[ii] += a[j];
                    }
                    t = 0;
                    continue;
                }
                if (!t) {
                    g[ii] += a[i];
                    if (a[i] != ' ') {
                        cur += a[i];
                    }
                    if (a[i] == ' ' || i == sz(a) - 1) {
                        if (!cur.empty()) { 
                            words[ii].push_back(cur);
                            cur.clear();
                        }
                    }
                }
            }
        }
        for (int ii = 0; ii < k; ii++) {
            memset(notcan[ii], 0, sizeof(notcan[ii]));
            if (ans[ii] == "?") {
                for (auto g: words[ii]) {
                    forbid(ii, g);
                }
            }
            if (ii < k - 1) {
                if (ans[ii + 1] != "?") {
                    notcan[ii][who[ans[ii + 1]]] = 1;
                }
            }
            if (ii > 0) {
                if (ans[ii - 1] != "?") {
                    notcan[ii][who[ans[ii - 1]]] = 1;
                }
            }
        }
        bool bad = 0;
        for (int i = 0; i < k; i++) {
            if (ans[i] != "?") {
                continue;
            }
            cans[i].clear();
            for (int j = 0; j < n; j++) {
                if (!notcan[i][j]) {
                    cans[i].push_back(j);
                }
            }
            if (sz(cans[i]) == 0) {
                bad = 1;
                break;
            }
            if (sz(cans[i]) == 1) {
                ans[i] = names[cans[i][0]];
            }
        }
        if (bad) {
            cout << "Impossible" << endl;
            continue;
        }
        while (true) {
            bool gg = 0;
            for (int ii = 0; ii < k; ii++) {
                if (ii < k - 1) {
                    if (ans[ii + 1] != "?") {
                        notcan[ii][who[ans[ii + 1]]] = 1;
                    }
                }
                if (ii > 0) {
                    if (ans[ii - 1] != "?") {
                        notcan[ii][who[ans[ii - 1]]] = 1;
                    }
                }
            }
            for (int i = 0; i < k; i++) {
                if (ans[i] != "?") {
                    continue;
                }
                cans[i].clear();
                for (int j = 0; j < n; j++) {
                    if (!notcan[i][j]) {
                        cans[i].push_back(j);
                    }
                }
                if (sz(cans[i]) == 0) {
                    bad = 1;
                    break;
                }
                if (sz(cans[i]) == 1) {
                    gg = 1;
                    ans[i] = names[cans[i][0]];
                }
            }
            if (bad) {
                break;
            }
            if (!gg) {
                break;
            }
        }
        for (int i = 0; i < k; i++) {
            if (ans[i] != "?") {
                continue;
            }
            if (i > 0) {
                if (ans[i - 1] != "?") {
                    notcan[i][who[ans[i - 1]]] = 1;
                }
            }
            bool good = 0;
            for (int j = 0; j < n; j++) {
                if (!notcan[i][j]) {
                    ans[i] = names[j];
                    good = 1;
                    break;
                }
            }
            if (!good) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            cout << "Impossible" << endl;
            continue;
        }
        for (int i = 1; i < k; i++) {
            if (ans[i] == ans[i - 1]) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            cout << "Impossible" << endl;
            continue;
        }
        for (int i = 0; i < k; i++) {
            cout << ans[i] << ':' << g[i] << endl;
        }
    }
    return 0;
}