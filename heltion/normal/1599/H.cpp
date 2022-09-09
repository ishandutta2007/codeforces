#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int query(int x, int y) {
    cout << "? " <<  x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    LL M = 1000000000;
    LL q1 = query(1, 1);
    LL q2 = query(1, M);
    LL q3 = query(M, 1);
    LL p1 = q1 + 2;
    LL p2 = q2 + 1 - M;
    LL p3 = M - 1 - q3;
    LL xM = (p1 + p3) / 2;
    LL yL = query(xM, 1) + 1;
    LL xL = p1 - yL;
    LL xR = p3 + yL;
    LL yR = xL - p2;
    cout << "! " << xL << " " << yL << " " << xR << " " << yR << "\n";
    return 0;
}


//xL - 1 + yL - 1 = q1
//xL - 1 + M - yR = q2
//M - xR + yL - 1 = q3

//xL + yL = p1
//xL - yR = p2
//xR - yL = p3

//xR + xL = p1 + p3