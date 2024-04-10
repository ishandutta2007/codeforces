#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=400010;
const int MAXLogN=22;

namespace SA { //{{{
    int sa[MAXLEN], rank[MAXLEN], height[MAXLEN], limit[MAXLEN];
    int wxa[MAXLEN], wxb[MAXLEN], wxc[MAXLEN];
    int str[MAXLEN];
    int len;
    void cal_sa() {
        int *x=wxa, *y=wxb, *c=wxc, size=MAXLEN-10;
        for(int i=0; i<=size; ++i) c[i]=0; //memset
        for(int i=1; i<=len; ++i) ++c[x[i]=(int)str[i]];
        for(int i=1; i<=size; ++i) c[i]+=c[i-1];
        for(int i=len; i>=1; --i) sa[c[x[i]]--]=i;

        for(int w=1; w<len; w*=2, size=len) {
            int p=0;
            for(int i=len-w+1; i<=len; ++i) y[++p]=i;
            for(int i=1; i<=len; ++i) if(sa[i]>w) y[++p]=sa[i]-w;

            for(int i=0; i<=size; ++i) c[i]=0; //memset
            for(int i=1; i<=len; ++i) ++c[x[i]];
            for(int i=1; i<=size; ++i) c[i]+=c[i-1];
            for(int i=len; i>=1; --i) sa[c[x[y[i]]]--]=y[i];
            std::swap(x, y); x[sa[1]]=1;
            for(int i=2; i<=len; ++i) {
                int j1=sa[i-1], j2=sa[i];
                int c1=y[j1], c2=y[j2];
                if(c1==c2) {
                    c1=(j1+w<=len?y[j1+w]:0);
                    c2=(j2+w<=len?y[j2+w]:0);
                }
                x[j2]=x[j1]+(c1<c2);
            }
        }
    }
    void cal_height() {
        for(int i=1; i<=len; ++i) rank[sa[i]]=i;
        for(int i=1, h=0; i<=len; ++i) {
            if(h>0) --h;
            int j=sa[rank[i]-1];
            while(i+h<=len && j+h<=len && str[i+h]==str[j+h])
                ++h;
            height[rank[i]]=h;
        }
    }
    int lcp_st[MAXLogN][MAXLEN];
    int lcp_k[MAXLEN], lcp_w[MAXLEN];
    void cal_lcp() {
        for(int i=2; i<=len; ++i) lcp_st[0][i]=height[i];
        for(int k=1, w=1; 2+w<=len; ++k, w*=2)
            for(int i=2; i+w<=len; ++i)
                lcp_st[k][i]=min(lcp_st[k-1][i], lcp_st[k-1][i+w]);
        for(int i=1, k=0, w=1; i<=len; ++i) {
            while(w*2<=i) w*=2, ++k;
            lcp_k[i]=k, lcp_w[i]=w;
        }
    }
    int lcp(int i, int j) {
        if(i==j) return limit[i];
        i=rank[i], j=rank[j]; if(i>j) swap(i, j);
        ++i;
        int k=lcp_k[j-i+1], w=lcp_w[j-i+1];
        return min(lcp_st[k][i], lcp_st[k][j-w+1]);
    }

    PII extend(int i, int lbound) {
        int j=rank[i]; i=j;
        forndown(k, MAXLogN) 
            if(i-(1<<k)>=1 && lcp_st[k][i-(1<<k)+1]>=lbound)
                i-=(1<<k);
        forndown(k, MAXLogN) 
            if(j+(1<<k)<=len && lcp_st[k][j+1]>=lbound)
                j+=(1<<k);
        return MP(i,j);
    }
}; //}}}

const int MAXN=200010;

struct Arr {
    int a[MAXLEN], n; // a is permutation

    VI tr[MAXLEN*4];
    void add(int x, int s, int t, int ind, int val) {
        tr[x].PB(val);
        if(s==t) return;
        int mid=(s+t)/2;
        if(ind<=mid) add(x*2, s, mid, ind, val);
            else add(x*2+1, mid+1, t, ind, val);
    }
    void pass(int x, int s, int t) {
        sort(all(tr[x]));
        if(s==t) return;
        int mid=(s+t)/2;
        pass(x*2, s, mid);
        pass(x*2+1, mid+1, t);
    }
    int query(int x, int s, int t, int st, int en, int le, int ri) {
        if(st<=s && t<=en) {
            auto i=lower_bound(all(tr[x]), le);
            auto j=lower_bound(all(tr[x]), ri+1);
            return (int)(j-i);
        }
        int mid=(s+t)/2, ans=0;
        if(st<=mid) ans+=query(x*2, s, mid, st, en, le, ri);
        if(mid<en) ans+=query(x*2+1, mid+1, t, st, en, le, ri);
        return ans;
    }

    void cal() {
        forint(i, 0, n*4) tr[i].clear();
        forint(i, 1, n)
            add(1, 1, n, i, a[i]);
        pass(1, 1, n);
    }
    int query(int l, int r, int le, int ri) {
        return query(1, 1, n, l, r, le, ri);
    }
} arr;


int main() {
    //ios_base::sync_with_stdio(false);

    int n, q; //cin>>n>>q;
    scanf("%d%d",&n,&q);
    static string s[MAXN];
    static int le[MAXN], ri[MAXN];
    //forint(i, 1, n) cin>>s[i];
    forint(i, 1, n) {
        static char buf[MAXN];
        scanf("%s", buf);
        s[i]=string(buf);
    }

    int null=500;
    SA::len=0;
    forint(i, 1, n) {
        le[i]=SA::len+1;
        for(char c: s[i]) SA::str[++SA::len]=(int)c;
        ri[i]=SA::len;
        SA::str[++SA::len]=null++;
    }
    SA::cal_sa();
    SA::cal_height();
    SA::cal_lcp();

    //forint(i, 1, n) printf("le[%d]=%d ri[%d]=%d\n",i,le[i],i,ri[i]);
    //forint(i, 1, SA::len) printf("sa[%d]=%d rank[%d]=%d\n",i,SA::sa[i],i,SA::rank[i]);


    arr.n=SA::len;
    forint(i, 1, arr.n) arr.a[i]=SA::sa[i];
    arr.cal();

    static PII es[MAXN];
    forint(k, 1, n) 
        es[k]=SA::extend(le[k], ri[k]-le[k]+1);

    while(q--) {
        int l, r, k; //cin>>l>>r>>k;
        scanf("%d%d%d",&l,&r,&k);
        PII e=es[k];
        int ans=arr.query(e.fi, e.se, le[l], ri[r]);
        //cout<<ans<<endl;
        printf("%d\n", ans);
    }

    return 0;
}