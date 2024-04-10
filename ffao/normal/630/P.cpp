    /* -*- coding: utf-8 -*-
     *
     * 0630P.cc: P. Area of a Star
     */
     
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include<iostream>
    #include<string>
    #include<vector>
    #include<map>
    #include<set>
    #include<stack>
    #include<list>
    #include<queue>
    #include<deque>
    #include<algorithm>
    #include<numeric>
    #include<utility>
    #include<complex>
    #include<functional>
     
    using namespace std;
     
    /* constant */
     
    const double PI = acos(-1.0);
     
    /* typedef */
     
    template <typename T>
    struct Pt {
      T x, y;
      Pt() {}
      Pt(T _x, T _y) : x(_x), y(_y) {}
      Pt(const Pt<T> &p) : x(p.x), y(p.y) {}
     
      Pt<T> operator+(const Pt<T> p) const { return Pt<T>(x + p.x, y + p.y); }
      Pt<T> operator-() const { return Pt<T>(-x, -y); }
      Pt<T> operator-(const Pt<T> p) const { return Pt<T>(x - p.x, y - p.y); }
      Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
      Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
      T dot(Pt<T> v) const { return x * v.x + y * v.y; }
      T cross(Pt<T> v) const { return x * v.y - y * v.x; }
      Pt<T> mid(const Pt<T> p) { return Pt<T>((x + p.x) / 2, (y + p.y) / 2); }
      T d2() { return x * x + y * y; }
      double d() { return sqrt(d2()); }
     
      Pt<T> rot(double th) {
        double c = cos(th), s = sin(th);
        return Pt<T>(c * x - s * y, s * x + c * y);
      }
     
      Pt<T> rot90() { return Pt<T>(-y, x); }
     
      bool operator==(const Pt<T> pt) const { return x == pt.x && y == pt.y; }
      bool operator<(const Pt<T> &pt) const {
        return x < pt.x || (x == pt.x && y < pt.y);
      }
     
      void print() { printf("(%d,%d)", x, y); }
    };
     
    typedef Pt<double> pt;
     
    struct CL {
      pt p;
      double t0, t1;
      CL() {}
      CL(const pt& _p, double _t0, double _t1) : p(_p), t0(_t0), t1(_t1) {}
    };
     
    /* global variables */
     
    /* subroutines */
     
    bool cross_lines(const pt& ap, const pt av, const pt& bp, const pt bv, CL& cl) {
      double op01 = av.cross(bv);
      //if (op01 == 0.0) return false; /* need to handle parallel?? */
     
      if (op01 == 0.0) {
        pt v = bp - ap;
        if (v.cross(av) != 0.0) return false;
     
        pt a1 = ap + av;
        pt b1 = bp + bv;
     
        return
          ((bp - ap).dot(b1 - ap) <= 0.0 ||
           (bp - a1).dot(b1 - a1) <= 0.0 ||
           (ap - bp).dot(a1 - bp) <= 0.0 ||
           (ap - b1).dot(a1 - b1) <= 0.0);
      }
     
      pt v = bp - ap;
      double op0 = v.cross(av);
      double op1 = v.cross(bv);
     
      double t0 = op1 / op01;
      double t1 = op0 / op01;
     
      cl.p = bv * t1 + bp;
      cl.t0 = t0;
      cl.t1 = t1;
     
      return true;
      //return (0.0 <= cl.t0 && cl.t0 <= 1.0 && 0.0 <= cl.t1 && cl.t1 <= 1.0);
    }
     
    /* main */
     
    int main() {
      //freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
     
      int n, r;
      scanf("%d%d", &n, &r);
     
      pt p0(r, 0);
      double dth = PI * 2 / n;
      pt p1 = p0.rot(dth * ((n - 1) / 2));
      pt p2 = p0.rot(dth);
      pt p3 = p0.rot(dth * (1 + (n + 1) / 2));
     
      CL cl;
      cross_lines(p0, p1 - p0, p2, p3 - p2, cl);
      //printf("%lf %lf\n", cl.p.x, cl.p.y);
     
      double s = cl.p.y * r * n;
      printf("%.12lf\n", s);
      return 0;
    }