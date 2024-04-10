#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

DB ans = 0;

int _X0, _Y0;
int _X1, _Y1;
int _X2, _Y2;
int _X3, _Y3;

DB dis(int x, int y, int _x, int _y){
    return sqrt((x - _x)*(x - _x) + (y - _y)*(y - _y));
}
void Check(int X0, int Y0, int X1, int Y1, int X2, int Y2, int X3, int Y3){
    if (X0 == X1 && Y0 == Y1) return;
    if (X0 == X2 && Y0 == Y2) return;
    if (X0 == X3 && Y0 == Y3) return;
    if (X1 == X2 && Y1 == Y2) return;
    if (X1 == X3 && Y1 == Y3) return;
    if (X2 == X3 && Y2 == Y3) return;
    DB t = dis(X0, Y0, X1, Y1) + dis(X1, Y1, X2, Y2) + dis(X2, Y2, X3, Y3);
    if (t > ans){
        ans = t;
        _X0 = X0, _Y0 = Y0;
        _X1 = X1, _Y1 = Y1;
        _X2 = X2, _Y2 = Y2;
        _X3 = X3, _Y3 = Y3;
    }
}

int x[20], y[20];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (!n) printf("%d %d\n%d %d\n%d %d\n%d %d\n",  0, 1, 0, m, 0, 0, 0, m - 1);
    else if (!m) printf("%d %d\n%d %d\n%d %d\n%d %d\n",  1, 0, n, 0, 0, 0, n - 1, 0);
    else{
        x[0] = 0, y[0] = 0;
        x[1] = 0, y[1] = 1;
        x[2] = 1, y[2] = 0;
        x[3] = 1, y[3] = 1;
        x[4] = n, y[4] = m;
        x[5] = n - 1, y[5] = m;
        x[6] = n, y[6] = m - 1;
        x[7] = n - 1, y[7] = m - 1;

        x[8] = 0, y[8] = m - 1;
        x[9] = 0, y[9] = m;
        x[10] = 1, y[10] = m - 1;
        x[11] = 1, y[11] = m;
        x[12] = n, y[12] = 0;
        x[13] = n - 1, y[13] = 0;
        x[14] = n, y[14] = 1;
        x[15] = n - 1, y[15] = 1;

        for (int i1 = 0; i1 < 16; i1++)
        for (int i2 = 0; i2 < 16; i2++)
        for (int i3 = 0; i3 < 16; i3++)
        for (int i4 = 0; i4 < 16; i4++)
            Check(x[i1], y[i1], x[i2], y[i2], x[i3], y[i3], x[i4], y[i4]);
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", _X0, _Y0, _X1, _Y1, _X2, _Y2, _X3, _Y3);
    }
}