#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void CR(int &n, int &m, int &x, int &y){
    int X = x, Y = y;
    x = Y; y = n - X + 1;
    swap(n, m);
}
void HR(int n, int m, int &x, int &y){
    y = m - y + 1;
}
void CCR(int &n, int &m, int &x, int &y){
    int X = x, Y = y;
    y = X; x = m - Y + 1;
    swap(n, m);
}
int main(){
    int n, m, x, y, z, p, X, Y;
    cin >> n >> m >> x >> y >> z >> p;
    x %= 4, y %= 2, z %= 4;
    for (int i = 0; i < p; i++){
        cin >> X >> Y;
        int N = n, M = m;
        for (int j = 0; j < x; j++) CR(N, M, X, Y);
        for (int j = 0; j < y; j++) HR(N, M, X, Y);
        for (int j = 0; j < z; j++) CCR(N, M, X, Y);
        cout << X << " " << Y << endl;
    }
}