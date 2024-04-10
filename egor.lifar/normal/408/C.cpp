#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>


using namespace std;



#define eps 0.00000001


struct point{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


struct line{
    point begin, end;
    line(){}
    line(point _begin, point _end) {
        begin = _begin;
        end = _end;;
    }
};


int a, b;


point lines(point l) {
    double a1, b1;
    a1 = -l.y;
    b1 = l.x;
    double d = a;
    a1 /= d;
    b1 /= d;//
    if (abs(b * a1 - int(b * a1)) >= eps || abs(b * b1 - int(b * b1)) >= eps) {
        return point(1000000, 1000000);
    }
    return point(int(b * a1), int(b * b1));
}



int main() {
    cin >> a >> b;
    for (int i = -2001; i <= 2001; i++) {
        for (int j = -2001; j <= 2001; j++) {
            if (abs(sqrt(i * i + j * j) - a) < eps && !(abs(i) == a && j == 0) && !(i == 0 && abs(j) == a)) {
                point p1(i, j);
                point p2 = lines(p1);
                if (p2.x != 1000000 && p2.x != p1.x && p2.y != p1.y && p2.x != 0 && p2.y != 0) {
                    cout << "YES" << endl;
                    cout << 0 << ' ' << 0 << endl;
                    cout << p1.x << ' ' << p1.y << endl;
                    cout << p2.x << ' ' << p2.y << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
	return 0;  
}