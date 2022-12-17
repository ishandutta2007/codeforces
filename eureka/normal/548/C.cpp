#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long lld;

template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(

template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
    if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
    if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

struct CRT{
    lld m, r;
    CRT(lld m=0, lld r=0):m(m), r(r){
    }
};

CRT crtmerge(CRT a, CRT b){
    CRT c;
    lld g, x, y;
    g = euclid(a.m, b.m, x, y);
    a.r %= a.m;
    b.r %= b.m;
    if((b.r-a.r)%g) return CRT(-1, -1);
    c.m = a.m * b.m / g;
    x = checkmod((b.r-a.r)/g*x, b.m/g);
    c.r = checkmod(a.m*x+a.r, c.m);
    return c;
}


int first(lld h, int x, int y, int m, int t){
    for (int i=0; i<=m; ++i){
	if (h == t) return i;
	h = (x * h + y) % m;
    }
    return -1;
}

int circle(lld t, int x, int y, int m){
    lld h = t;
    for (int i=0; i<=m; ++i){
	if (i!=0 && h == t) return i;
	h = (x * h + y) % m;
    }
    return -1;
}

CRT read(int m){
    int h, a, x, y;
    cin >> h >> a >> x >> y;
    int f = first(h, x, y, m, a);
    int c = -1;
    if (f != -1) c = circle(a, x, y, m);
    return CRT(c, f);
}

int main(){
    int m;
    cin >> m;
    CRT c1 = read(m);
    CRT c2 = read(m);
    lld ans = -1;
    if (c1.r != -1 && c2.r != -1){
	if (c1.m != -1 && c2.m != -1){
	    CRT c = crtmerge(c1, c2);
	    if (c.r == -1) {
		ans = -1;
	    }else{
		ans = c.r;
		while (ans < c1.r || ans < c2.r) ans += c.m;
	    }
	}else if (c1.m != -1 || c2.m != -1){
	    if (c2.m == -1) swap(c1, c2);
	    if (c1.r >= c2.r && (c1.r - c2.r) % c2.m == 0) ans = c1.r;
	    else ans = -1;
	}else if (c1.r == c2.r){
	    ans = c1.r;
	}
    }
    cout << ans << endl;
    return 0;
}