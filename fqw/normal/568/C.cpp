// 19:59
// 20:33 - 21:04 - wa
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int MAXN=220;

bool g[MAXN*2][MAXN*2];
char str[MAXN], ans[MAXN];
char type[33];
int n, num;

struct Status {
    int a[MAXN*2]; // 0: unknown; 1: yes; 2: no
    bool p(int i, int c) {
        if(a[i]>0) return a[i]==c;
        a[i]=c;
        if(!p(i>n?i-n:i+n, 3-c)) return false;
        if(c==1) {
            rep(j, 1, n*2) if(g[i][j]) if(!p(j, c)) return false;
        } else {
            rep(j, 1, n*2) if(g[j][i]) if(!p(j, c)) return false;
        }
        return true;
    }
    bool ok(int able[]) {
        rep(i, 1, n) if(a[i]>0 && a[i]==a[i+n]) return false;
        rep(i, 1, n) if(a[i]>0 && able[i]<2) {
            int c=(a[i]==2);
            if(able[i]!=c) return false;
        }
        return true;
    }
};

bool solve() {
    rep(i, 1, n) if(g[i][i+n] && g[i+n][i]) return false;

    auto func=[](int p) -> bool {
        int able[MAXN];
        bool has0=false, has1=false;
        rep(i, 1, num) { if(type[i]=='V') has0=true; else has1=true; }
        if(has0 && has1) able[0]=2; else if(has0) able[0]=0; else able[0]=1;
        rep(i, 1, n) able[i]=able[0];

        Status st; fillchar(st.a, 0);
        rep(i, 1, p) {
            ans[i]=str[i];
            int want=(type[str[i]-'a'+1]=='V');
            //printf("p=%d i=%d w=%d\n",p,i,want);
            if(!st.p(i+want*n, 1)) return false;
            able[i]=want;
        }

        rep(i, p+1, n) {
            int minp=(i==p+1?int(str[p+1]-'a'+1)+1:1);
            if(minp>num) return false;
            bool has[2]={false,false}; int first=(type[minp]=='V');
            rep(k, minp, num) {
                has[type[k]=='V']=true;
            }
            bool flag=false;
            repn(k, 2) {
                if(!has[first^k]) continue;
                able[i]=(first^k);
                Status s0=st;
                if(s0.p(i+n*(first^k), 1) && s0.ok(able)) {
                    int cur=minp; while((type[cur]=='V')!=(first^k)) ++cur;
                    ans[i]=char('a'+cur-1);
                    flag=true;
                    st=s0;
                    break;
                }
            }
            if(!flag) return false;
        }
        ans[n+1]='\0';
        printf("%s\n", ans+1);
        return true;
    };

    irep(p, n, 0) if(func(p)) return true;
    return false;
}

int main() {
    scanf("%s", type+1); 
    num=(int)strlen(type+1);

    int m; scanf("%d%d", &n,&m);
    fillchar(g, false);
    rep(k, 1, m) {
        int i, j; char ti[9], tj[9];
        scanf("%d%s%d%s", &i,ti,&j,tj);
        int ci=(ti[0]=='V');
        int cj=(tj[0]=='V');
        g[i+ci*n][j+cj*n]=true;
        g[j+(cj^1)*n][i+(ci^1)*n]=true;
    }
    rep(i, 1, n*2) g[i][i]=true;
    rep(k, 1, n*2) rep(i, 1, n*2) rep(j, 1, n*2)
        if(g[i][k] && g[k][j])
            g[i][j]=true;
    scanf("%s", str+1);

    if(!solve()) printf("-1\n");

    return 0;
}