#include <iostream>
using namespace std;

long long gcd(long long a, long long b){if (!b) return a; return gcd(b, a % b);}

long long n, m, x, y, a, b, t, x1, x2, y1, y2, lx, rx, ly, ry;
int main(){
    cin >> n >> m >> x >> y >> a >> b;

    t = gcd(a, b);

    a /= t; b /= t;
    x1 = n / a * a;
    y1 = n / a * b;
    
    if (y1 > m){
        x1 = m / b * a;
        y1 = m / b * b;
    }
    if (x1 % 2 == 0){
        lx = x - x1 / 2;
        rx = x + x1 / 2;
    }else{
        lx = x - x1 / 2 - 1;
        rx = x + x1 / 2;
    }
    if (y1 % 2 == 0){
        ly = y - y1 / 2;
        ry = y + y1 / 2;
    }else {
        ly = y - y1 / 2 - 1;
        ry = y + y1 / 2;
    }
    if (rx > n){
        lx = lx - rx + n;
        rx = n;
    }
    if (lx < 0){
        rx = rx - lx;
        lx = 0;
    }
    if (ry > m){
        ly = ly - ry + m;
        ry = m;
    }
    if (ly < 0){
        ry = ry - ly;
        ly = 0;
    }
    cout << lx << " " << ly << " " << rx << " " << ry << endl;
}