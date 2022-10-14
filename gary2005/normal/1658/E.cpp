/**
 *    author:  gary
 *    created: 27.03.2022 22:29:41
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,k;
int v[2002][2002];
bool cmp(mp A,mp B){
    return v[A.first][A.second]>v[B.first][B.second];
}
char ans[2002][2002];
namespace io {
        const int SIZE = (1 << 21) + 1;
        char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
        // getchar
        #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
        // print the remaining part
        inline void flush () {
                fwrite (obuf, 1, oS - obuf, stdout);
                oS = obuf;
        }
        // putchar
        inline void putc (char x) {
                *oS ++ = x;
                if (oS == oT) flush ();
        }
        // input a signed integer
        template <class I>
        inline void gi (I &x) {
                for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
                for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
        }
        // print a signed integer
        template <class I>
        inline void print (I x) {
                if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
                while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
                while (qr) putc (qu[qr --]);
        }
        //no need to call flush at the end manually!
        struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
bool win[2002][2002];
void solve(){
    gi(n);
    gi(k);
    rb(i,1,n) rb(j,1,n) gi(v[i][j]);
    vector<mp> rnk;
    rb(i,1,n) rb(j,1,n) rnk.PB(II(i,j));
    sort(ALL(rnk),cmp);
    deque<mp> xy,yx;
    rb(i,1,n) rb(j,1,n) win[i][j]=1,xy.PB(II(i+j,i-j)),yx.PB(II(i-j,i+j));
    sort(ALL(xy));
    sort(ALL(yx));
    for(auto it:rnk){
        int x,y;
        tie(x,y)=it;
        if(win[x][y]){
            ans[x][y]='M';
            tie(x,y)=II(x+y,x-y);
            while (!xy.empty()){
                if(xy.front().first<x-k){
                    int xx,yy;
                    tie(xx,yy)=xy.front();
                    xy.pop_front();
                    tie(xx,yy)=II((xx+yy)/2,(xx-yy)/2);
                    win[xx][yy]=0;
                }
                else break;
            }
            while (!xy.empty()){
                if(xy.back().first>x+k){
                    int xx,yy;
                    tie(xx,yy)=xy.back();
                    xy.pop_back();
                    tie(xx,yy)=II((xx+yy)/2,(xx-yy)/2);
                    win[xx][yy]=0;
                }
                else break;
            }
            while (!yx.empty()){
                if(yx.front().first<y-k){
                    int xx,yy;
                    tie(yy,xx)=yx.front();
                    yx.pop_front();
                    tie(xx,yy)=II((xx+yy)/2,(xx-yy)/2);
                    win[xx][yy]=0;
                }
                else break;
            }
            while (!yx.empty()){
                if(yx.back().first>y+k){
                    int xx,yy;
                    tie(yy,xx)=yx.back();
                    yx.pop_back();
                    tie(xx,yy)=II((xx+yy)/2,(xx-yy)/2);
                    win[xx][yy]=0;
                }
                else break;
            }
        }
        else{
            ans[x][y]='G';
        }
    }
    rb(i,1,n){
        rb(j,1,n) putc(ans[i][j]);
        putc('\n');
    }
}
int main(){
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}