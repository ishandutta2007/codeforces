#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>


using namespace std;


#define eps 0.000001


int main() {
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double a, b, c;
    a = by - ay;
    b = ax - bx;
    c = -(a * bx + b * by);
    if (abs(a * cx + b * cy + c) < eps) {
        cout << "TOWARDS";
    } else {
        if (a * cx + b * cy + c < 0) {
            cout << "LEFT";
        } else {
            cout << "RIGHT";
        }
    }
    cout << endl;
    return 0;
}