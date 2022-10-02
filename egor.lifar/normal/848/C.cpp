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
#define lowbit(x) ((x)&-(x))
const int MAXN = 100005, MAXM = 10000005;


int ls[MAXM], rs[MAXM], rt[MAXN], n, a[MAXN], m, ndc;
set<int> dat[MAXN];
long long sum[MAXM];
void update(int&x,int l,int r,int p,int u){
    if(!x)x=++ndc;sum[x]+=u;if(l==r)return;int mid=(l+r)>>1;
    if(p<=mid)update(ls[x],l,mid,p,u);else update(rs[x],mid+1,r,p,u);
}
long long ask(int&x,int l,int r,int s,int t){
    if(!x||l==s&&r==t)return sum[x];int mid=(l+r)>>1;
    if(t<=mid)return ask(ls[x],l,mid,s,t);
    if(s>mid)return ask(rs[x],mid+1,r,s,t);
    return ask(ls[x],l,mid,s,mid)+ask(rs[x],mid+1,r,mid+1,t);
}
void modify(int x,int y,int u){while(x<=n)update(rt[x],1,n,y,u),x+=lowbit(x);}
long long query(int x,int y){
    long long ret=0;
    while(x)ret+=ask(rt[x],1,n,1,y),x-=lowbit(x);
    return ret;
}
void add(int p,int x){
    dat[p].insert(x);
    auto it=dat[p].find(x),pre=it,suf=it;
    bool f1=false,f2=false;
    if(pre!=dat[p].begin())--pre,modify(*pre,x,x-*pre),f1=1;
    ++suf;
    if(suf!=dat[p].end())modify(x,*suf,*suf-x),f2=1;
    if(f1&&f2)modify(*pre,*suf,-(*suf-*pre));
}
void del(int p,int x){
    auto it=dat[p].find(x),pre=it,suf=it;
    bool f1=false,f2=false;
    if(pre!=dat[p].begin())--pre,modify(*pre,x,-(x-*pre)),f1=1;
    ++suf;
    if(suf!=dat[p].end())modify(x,*suf,-(*suf-x)),f2=1;
    if(f1&&f2)modify(*pre,*suf,*suf-*pre);
    dat[p].erase(x);
}


int main() {
    n = readInt(), m = readInt();
    for(int i = 1; i <= n; i++){
        a[i] = readInt();
        add(a[i], i);
    }
    for (int i = 1; i <= m;i++){
        int o = readInt(), u = readInt(), v = readInt();
        if (o == 1){
            del(a[u],u);
            a[u] = v;
            add(a[u], u);
        } else {
            printf("%lld\n", query(n, v) - query(u - 1, v));
        }
    }
    return 0;
}