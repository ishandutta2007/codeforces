#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

double sqr(double a)
{
    return a * a;
}


bool doubleEqual(double a, double b)
{
    return fabs(a - b) < 1e-9;
}


bool doubleLessOrEqual(double a, double b)
{
    return a < b || doubleEqual(a, b);
}


bool doubleLess(double a, double b)
{
    return a < b && !doubleEqual(a, b);
}


bool doubleGreaterOrEqual(double a, double b)
{
    return a > b || doubleEqual(a, b);
}


bool doubleGreater(double a, double b)
{
    return a > b && !doubleEqual(a, b);
}


double mySqrt(double a)
{
    if(doubleLess(a, 0) )
    {
        throw "sqrt(-1)";
    }
    if(a < 0) return 0;
    return sqrt(a);
}


struct Point{
    double x, y; public:
    Point(): x(0), y(0) {} //   
    
    Point(double x, double y): x(x), y(y) {} //      Point(x = 0...)
    //      Point A = 2;
    
    void scan() //   
    {
        cin >> x >> y;
    }
    
    void print() const //   
    {
        cout << fixed << setprecision(16) << x << " " << y << " ";
    }
    
    Point operator+(const Point & p) const //  2 
    {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator-(const Point & p) const //  2 
    {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator-() const //  
    {
        return Point(-x, -y);
    }
    
    Point operator*(double k) const //    
    {
        return Point(x * k, y * k);
    }
    
    Point operator/(double k) const //    
    {
        return Point(x / k, y / k);
    }
    
    double operator%(const Point & p) const //  
    {
        return x * p.x + y * p.y;
    }
    
    double operator*(const Point & p) const //  
    {
        return x * p.y - y * p.x;
    }
    
    double length() const //      . (   )
    {
        return mySqrt(*this % *this);
    }
    
    double distTo(const Point & p) const //  2  -    
    {
        return (*this - p).length();
    }
    
    double distTo(const Point & A, const Point & B) const //      ( >= 0)
    {
        double d = A.distTo(B);
        if(doubleEqual(d, 0) ) //    ! 
        {
            throw "A = B";
        }
        double s = (*this - A) * (*this - B); //   
        return fabs(s) / d; //  
    }
    
    Point normalize(double k = 1) const //     k
    {
        double len = length(); //  
        if(doubleEqual(len, 0) ) //   
        {
            if(doubleEqual(k, 0) )
            {
                return Point();
            }
            throw "zero-size vector"; //     
        }
        return *this * (k / len);
    }
    
    Point getH(const Point & A, const Point & B) const //       (A, B)
    {
        Point C = *this;
        Point v = B - A; //   
        Point u = C - A; // ,    
        double k = v % u / v.length(); //   
        v = v.normalize(k); //   u  v
        Point H = A + v; //   A     u,   A
        return H;
    }
    
    Point rotate() const //   90     ( )
    {
        return Point(-y, x);
    }
    
    Point rotate(double alpha) const //    alpha   
    // (  ,  alpha < 0)
    {
        return rotate(cos(alpha), sin(alpha) ); //     
    }
    
    Point rotate(double cosa, double sina) const //      
    {
        Point v = *this;
        Point u = v.rotate(); // ,  v,  (v, u) - ,     
        Point w = v * cosa + u * sina; //     (v, u),  w
        return w;
    }
    
    bool isZero() const //   ,        
    {
        return doubleEqual(x, 0) && doubleEqual(y, 0);
    }
    
    bool isOnLine(const Point & A, const Point & B) const //   ?
    {
        return doubleEqual( (A - *this) * (B - *this), 0);
    }
    
    bool isInSegment(const Point & A, const Point & B) const //   ?
    {
        return isOnLine(A, B) && doubleLessOrEqual( (A - *this) % (B - *this), 0 );
    }
    
    bool isInSegmentStrictly(const Point & A, const Point & B) const //    ?
    {
        return isOnLine(A, B) && doubleLess( (A - *this) % (B - *this), 0 );
    }
    
    double getAngle() const
    {
        return atan2(y, x); //      
    }
    
    double getAngle(Point u) const
    {
        Point v = *this;
        return atan2(v * u, v % u); //    
    }
    
};


int getIntersection //    (A, B)   (O, r)
(
 const Point & A,
 const Point & B,
 const Point & O,
 double r,
 Point & M,
 Point & N
 )
{
    double h = O.distTo(A, B);
    if(doubleLess(r, h) ) //    
    {
        return 0;
    }
    Point H = O.getH(A, B); //   AB
    Point v = B - A; //   
    double k = mySqrt(sqr(r) - sqr(h) ); // ,     H      
    v = v.normalize(k);
    M = H + v;
    N = H - v;
    if(v.isZero() ) return 1;
    return 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int R;
    Point O, A;
    cin >> R;
    O.scan();
    A.scan();
    if (doubleGreaterOrEqual(O.distTo(A), R)) {
        O.print();
        cout << R << endl;
        return 0;
    }
    if (doubleEqual(O.distTo(A), 0)) {
        A = Point(O.x + R, O.y);
        Point v = (O - A) / 2;
        (A + v).print();
        cout << fixed << setprecision(16) << v.length() << endl;
        return 0;
    }
    Point B, C;
    getIntersection(O, A, O, R, B, C);
    if (B.distTo(A) < C.distTo(A)) swap(B, C);
    Point v = (B - A) / 2;
    (A + v).print();
    cout << fixed << setprecision(16) << v.length() << endl;
}