#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>



#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble;

using namespace std;

namespace CodigoDeNotebook
{

    typedef tint tipo;
    #define BASE 1000000
    #define LMAX 8

    struct Long {
        int l;
        tipo n[LMAX];
        Long(tipo x) { 	l = 0; forn(i, LMAX) { n[i]=x%BASE; l+=!!x||!i; x/=BASE;} }
        Long(){*this = Long(0);}
    };

    void invar(Long &a) {
        fill(a.n+a.l, a.n+LMAX, 0);
        while(a.l>1 && !a.n[a.l-1]) a.l--;
    }

    void lsuma(const Long&a, const Long&b, Long&c) { // c = a + b
        c.l = max(a.l, b.l);
        tipo q = 0;
        forn(i, c.l) q += a.n[i]+b.n[i], c.n[i]=q%BASE, q/=BASE;
        if(q) c.n[c.l++] = q;
        invar(c);
    }
    Long& operator+= (Long&a, const Long&b) { lsuma(a, b, a); return a; }
    Long operator+ (const Long&a, const Long&b) { Long c; lsuma(a, b, c); return c; }

    bool lresta(const Long&a, const Long&b, Long&c) { // c = a - b
        c.l = max(a.l, b.l);
        tipo q = 0;
        forn(i, c.l) q += a.n[i]-b.n[i], c.n[i]=(q+BASE)%BASE, q=(q+BASE)/BASE-1;
        invar(c);
        return !q;
    }
    Long& operator-= (Long&a, const Long&b) { lresta(a, b, a); return a; }
    Long operator- (const Long&a, const Long&b) {Long c; lresta(a, b, c); return c;}

    bool operator< (const Long&a, const Long&b) { Long c; return !lresta(a, b, c); }
    bool operator<= (const Long&a, const Long&b) { Long c; return lresta(b, a, c); }
    bool operator== (const Long&a, const Long&b) { return a <= b && b <= a; }

    void lmul(const Long&a, const Long&b, Long&c) { // c = a * b
        c.l = a.l+b.l;
        fill(c.n, c.n+b.l, 0);
        forn(i, a.l) {
            tipo q = 0;
            forn(j, b.l) q += a.n[i]*b.n[j]+c.n[i+j], c.n[i+j] = q%BASE, q/=BASE;
            c.n[i+b.l] = q;
        }
        invar(c);
    }

    Long& operator*= (Long&a, const Long&b) { Long c; lmul(a, b, c); return a=c; }
    Long operator* (const Long&a, const Long&b) { Long c; lmul(a, b, c); return c; }

    
};

struct pto
{
    pto() : pto(0,0) {}
    pto(tint xx, tint yy) : x(xx), y(yy) {}
    tint x,y;
    int i;
    tint operator * (const pto &o) const { return x*o.x + y*o.y;}
    tint operator ^ (const pto &o) const { return x*o.y - y*o.x;}
};

int cuad(const pto &p)
{
    if (p.x > 0 && p.y >= 0) return 1;
    if (p.x <= 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y <= 0) return 3;
    if (p.x >= 0 && p.y < 0) return 4;
    assert(false);
}

bool comp(const pto &a,const pto &b)
{
    int ca = cuad(a);
    int cb = cuad(b);
    if (ca != cb) return ca < cb;
    return (a^b) > 0;
}

tint signum(tint x)
{
    return (x > 0) - (x < 0);
}

struct Fraction
{
    Fraction(tint n, tint d) : num(n), den(d) {}
    tint num,den;
    bool operator <(const Fraction &o) const 
    {
        if (signum(num) != signum(o.num))
            return signum(num) < signum(o.num);
        tint anum, onum;
        bool swapped;
        if (signum(num) < 0)
        {
            anum = -num;
            onum = -o.num;
            swapped = true;
        }
        else
        {
            anum = num;
            onum = o.num;
            swapped = false;
        }
        CodigoDeNotebook::Long a(anum);
        a *= o.den;
        CodigoDeNotebook::Long b(onum);
        b *= den;
        if (swapped)
            return b < a;
        else
            return a < b;
    }
};

int main()
{
    int n; cin >> n;
    vector<pto> v(n);
    forn(i,n)
    {
        long long x,y;
        cin >> x >> y;
        v[i].x = x;
        v[i].y = y;
        v[i].i = i+1;
    }
    sort(v.begin(),v.end(),comp);
    int bestI = 0, bestJ = 1;
    Fraction bestF(-10, 1);
    forn(i, n)
    {
        int next = (i+1)%n;
        tint product = v[i] * v[next];
        Fraction f(signum(product) * product * product , (v[i]*v[i]) * (v[next]*v[next]));
        if (bestF < f)
        {
            bestI = i;
            bestJ = next;
            bestF = f;
        }
    }
    cout << v[bestI].i << " " << v[bestJ].i << endl;
    return 0;
}