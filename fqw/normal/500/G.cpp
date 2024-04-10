// (8.10) 21:51
//
// (8.11) 
// (known how to do) 
// 21:39 - 22:48 (made it clear)
//               (but time to sleep)
//
// (8.12) 
// 20:28 - 21:31 - wa sample
//       - 21:46 - pass sample - wa 2
//       - 22:04 - wa 4
// 22:30 - 23:06 - wa 11
//
// (8.13)
// 23:20 - 00:03 - tle 48
//#include <cassert>
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
#define assert(args...) {}
#ifdef DEBUG
    #define _debug(args...) { printf(args); fflush(stdout); }
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
template<class T> T ext_gcd(T a, T b, T &x, T &y) {
    if(b==0) { x=1, y=0; return a; }
    LL nx, ny, d; d=ext_gcd(b, a%b, nx, ny);
    x=ny, y=nx-(a/b)*ny;
    return d;
}

const int MAXN=200010;
const int MAXLog=20;
const LL NO=1LL<<55;

int up[MAXN][MAXLog], dep[MAXN];
VI es[MAXN];
int n;

//{{{
int lst[MAXN*2], ind[MAXN], cnt;
PII lca_rmq[MAXN*2][MAXLog]; 
int lca_log[MAXN*2];

void dfs(int x, int fa) {
    dep[x]=dep[fa]+1; up[x][0]=fa;
    lst[++cnt]=x, ind[x]=cnt;
    for(int i=0; up[x][i]>0; ++i) up[x][i+1]=up[up[x][i]][i];
    for(int y: es[x]) if(y!=fa) {
        dfs(y, x);
        lst[++cnt]=x;
    }
}

void pre() {
    fillchar(up, 0);
    fillchar(dep, 0);
    cnt=0;
    dfs(1, 0);
    rep(i, 1, cnt) lca_rmq[i][0]=mp(dep[lst[i]], lst[i]);
    repn(j, MAXLog-1)
        rep(i, 1, cnt-(1<<j))
            lca_rmq[i][j+1]=min(lca_rmq[i][j], lca_rmq[i+(1<<j)][j]);

    fillchar(lca_log, 0xff);
    repn(j, MAXLog) if((1<<j)<=cnt) lca_log[1<<j]=j;
    rep(i, 1, cnt) if(lca_log[i]<0) lca_log[i]=lca_log[i-1];
}

int lca(int x, int y) {
    int i=ind[x], j=ind[y];
    if(i>j) swap(i, j);
    int k=lca_log[j-i+1];
    PII r=min(lca_rmq[i][k], lca_rmq[j-(1<<k)+1][k]);
    return r.se;
    /*
    int d=dep[x]-dep[y];
    if(d>0) x=go_up(x, d); else y=go_up(y, -d);
    irepn(i, MAXLog) if(up[x][i]!=up[y][i]) x=up[x][i], y=up[y][i];
    if(x!=y) x=up[x][0], y=up[y][0];
    assert(x==y && x!=0);
    return x;
    */
}

int go_up(int x, int d) {
    irepn(i, MAXLog) if(d&(1<<i)) x=up[x][i];
    return x;
}

int dis(int x, int y) {
    int z=lca(x, y);
    return dep[x]+dep[y]-2*dep[z];
}

int go(int x, int y, int d) {
    int z=lca(x, y);
    int dx=dep[x]-dep[z];
    int dy=dep[y]-dep[z];
    assert(d>=0 && d<=dx+dy);
    if(d<=dx) return go_up(x, d);
        else return go_up(y, dx+dy-d);
}

int proj(int p, int x, int y) {
    int d=dis(p, x)+dis(p, y)-dis(x, y);
    assert(d%2==0); d/=2;
#ifdef DEBUG
    assert(go(p, x, d)==go(p, y, d));
#endif
    return go(p, x, d);
}

//}}}


LL solve_a(LL, LL, LL, LL);
LL solve_b(LL, LL, LL, LL, LL, LL);
LL solve_c(LL, LL, LL, LL, LL);
LL solve_d(LL, LL, LL, LL);

// find k>=0:
//   t1*k+p1 == t2*k+p2
//   min: t1*k+p1
LL solve_a(LL t1, LL p1, LL t2, LL p2) { 
    //{{{
    if(p1>p2) swap(t1, t2), swap(p1, p2);
    if(p1==p2) return p1;
    // p1+t1*x = p2+t2*y
    // t1*x + t2*(-y) = p2-p1
    LL x, y, g=ext_gcd(t1, t2, x, y); 
    y=-y; // now x*t1-y*t2=g
    if((p2-p1)%g!=0) return NO;
    LL times=(p2-p1)/g; x*=times, y*=times; // now x*t1-y*t2=p2-p1
    LL z1=t2/g, z2=t1/g; // we can do: x+=z1, y+=z2

    // add x & y
    LL ux=0; if(x<0) ux=(-x-1)/z1+1;
    LL uy=0; if(y<0) uy=(-y-1)/z2+1;
    LL u=max(ux, uy); x+=z1*u, y+=z2*u;
    // dec x & y
    LL vx=x/z1, vy=y/z2, v=min(vx, vy);
    x-=z1*v, y-=z2*v;

    assert(p1+x*t1==p2+y*t2);
    assert(x>=0 && y>=0);

    return p1+x*t1;
} //}}}

LL solve_b(LL t1, LL l1, LL r1, LL t2, LL l2, LL r2) {
    //{{{
    /*
    {
        LL ans=NO;
        repn(k1, 30) repn(k2, 30) {
            LL x1=l1+t1*k1, y1=r1+t1*k1;
            LL x2=l2+t2*k2, y2=r2+t2*k2;
            LL x=max(x1, x2), y=min(y1, y2);
            if(x<=y && (y-x)%2==0) 
                setmin(ans, (x+y)/2);
        }
        return ans;
    }
    //*/
    _debug("\nB (%lld,%lld,%lld) (%lld,%lld,%lld)\n",t1,l1,r1,t2,l2,r2);
    auto cal=[](LL t1, LL p1, LL t2, LL p2, LL d) -> LL {
        if((p2-p1)%2==0) {
            if(t1%2==0 && t2%2==0) return solve_c(t1, p1, t2, p2, d);
            if(t1%2==1 && t2%2==0) return solve_c(t1*2, p1, t2, p2, d);
            if(t1%2==0 && t2%2==1) return solve_c(t1, p1, t2*2, p2, d);
            LL ans=NO;
            setmin(ans, solve_c(t1*2, p1, t2*2, p2, d));
            setmin(ans, solve_c(t1*2, p1+t1, t2*2, p2+t2, d));
            return ans;
        } else {
            if(t1%2==0 && t2%2==0) return NO;
            if(t1%2==1 && t2%2==0) return solve_c(t1*2, p1+t1, t2, p2, d);
            if(t1%2==0 && t2%2==1) return solve_c(t1, p1, t2*2, p2+t2, d);
            LL ans=NO;
            setmin(ans, solve_c(t1*2, p1+t1, t2*2, p2, d));
            setmin(ans, solve_c(t1*2, p1, t2*2, p2+t2, d));
            return ans;
        }
    };
    assert(r1-l1==r2-l2);
    LL ans=NO, d=r1-l1;
    setmin(ans, cal(t1, l1, t2, r2, d));
    setmin(ans, cal(t2, l2, t1, r1, d));
    _debug("ans=%lld\n", ans);
    return ans;
} //}}}

// find k1, k2:
//    (p2+t2*k2) - (p1+t1*k1) \in [0,d]
//    return min: ((..) + (..)) / 2
LL solve_c(LL t1, LL p1, LL t2, LL p2, LL d) {
    //{{{
    /*
    {
        LL ans=NO;
        repn(k1, 50) repn(k2, 50) {
            LL x=p1+t1*k1, y=p2+t2*k2;
            if(y-x>=0 && y-x<=d) setmin(ans, (x+y)/2);
        }
        return ans;
    }
    //*/

    _debug(" -> (%lld,%lld) (%lld,%lld) d=%lld\n",t1,p1,t2,p2,d);
    LL p=p2-p1, t=t2;
    if(p<0) p+=t2;
    // now want: (k*t+p)%t1 <= d
    LL M=t1, m=t%M, l=(-p%M+M)%M, r=((d-p)%M+M)%M;
    //if(l<=r) assert(r-l+1==d+1); else assert((M-1-l+1)+(r-0+1)==d+1);
    //t%=t1; LL l=(-p%t1+t1)%t1, r=((d-p)%t1+t1)%t1;
    LL z;
    if(l<=r) z=solve_d(M, m, l, r);
    else {
        z=NO;
        setmin(z, solve_d(M, m, l, M-1));
        setmin(z, solve_d(M, m, 0, r));
    }
    _debug("    p=%lld t=%lld l=%lld r=%lld z=%lld\n",p,t,l,r,z);
    if(z==NO) return NO;
    LL q2=z*t+p+p1;
    LL q1=(q2-p1)/t1*t1+p1;
    _debug("    q2=%lld q1=%lld\n",q2,q1);
    return (q1+q2)/2;
} //}}}

// find k:
//   m*k % M \in [l,r]
//   return min: m*k
LL solve_d(LL M, LL m, LL l, LL r) {
    //{{{
    /*
    {
        repn(k, 2055) if(k*m%M>=l && k*m%M<=r) return k;
        return NO;
    }
    //*/
    assert(l>=0 && l<M);
    assert(r>=0 && r<M && l<=r);
    if(m==0) return l==0?0:NO;
    if(l==0) return 0;

    if(m*2>M) return solve_d(M, M-m, M-r, M-l);
    LL k=(l+m-1)/m; if(k*m<=r) return k;

    assert(l/m==r/m);
    LL l0=l%m, r0=r%m, m0=(-M%m+m)%m;
    LL t=solve_d(m, m0, l0, r0);
    if(t==NO) return NO;
    return (l+M*t+m-1)/m;
} //}}}

LL solve(int a, int b, int x, int y) { //{{{
    _debug("a=%d b=%d x=%d y=%d\n", a,b,x,y);
    int pa=proj(a, x, y);
    int pb=proj(b, x, y);
    if(pa==pb && proj(pa, a, b)!=pa) // no intersect
        return NO;

    int nc=dis(pa, pb);
    int na=dis(a, pa), nb=dis(b, pb), nx, ny;
    bool rev=false;
    if(dis(x, pa)<=dis(x, pb)) {
        nx=dis(x, pa), ny=dis(y, pb);
    } else {
        rev=true;
        nx=dis(x, pb), ny=dis(y, pa);
    }
    int t1=(na+nb+nc)*2, t2=(nx+ny+nc)*2;
    LL ans=NO;
    _debug("nc=%d na=%d nb=%d nx=%d ny=%d rev=%d\n", nc,na,nb,nx,ny,rev);

    // same dir
    {
        int u1=na, v1=na+nc+2*nb;
        int u2=nx, v2=nx+nc+2*ny;
        if(rev) swap(u2, v2);
        setmin(ans, solve_a(t1, u1, t2, u2));
        setmin(ans, solve_a(t1, v1, t2, v2));
    }

    // diff dir
    if(!rev) {
        setmin(ans, solve_b(t1, na, na+nc, t2, nx+nc+2*ny, nx+2*nc+2*ny));
        setmin(ans, solve_b(t1, na+nc+2*nb, na+2*nc+2*nb, t2, nx, nx+nc));
    } else {
        setmin(ans, solve_b(t1, na, na+nc, t2, nx, nx+nc));
        setmin(ans, solve_b(t1, na+nc+2*nb, na+2*nc+2*nb, t2, nx+nc+2*ny, nx+2*nc+2*ny));
    }
    return ans;
} //}}}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, n-1) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }
    pre();

    /*
    FILE *f=fopen("g2.ans","r"); VI std;
    for(int x; fscanf(f, "%d", &x)>0; std.pb(x));
    fclose(f);
    //*/

    //rep(i, 1, n) printf("dep[%d]=%d  fa[%d]=%d\n", i,dep[i],i,up[i][0]);

    int cs; scanf("%d", &cs);
    //VL answers;
    repn(k, cs) {
        int a, b, x, y; scanf("%d%d%d%d", &a,&b,&x,&y);
        LL ans=solve(a, b, x, y);
        if(ans==NO) ans=-1;
        //answers.pb(ans);
        printf("%lld\n", ans);
    //if(ans!=std[k]) { printf("error: %d %d %d %d | ans=%d std=%d\n",a,b,x,y,(int)ans,std[k]);}
    }
    //for(LL ans: answers) printf("%lld\n", ans);
    return 0;
}