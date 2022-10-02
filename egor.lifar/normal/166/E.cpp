#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


#define INF 1000000007


int n;
int d[10000001][4];


int main() {
    cin >> n;
    d[0][0] = 1;
    d[0][1] = 0;
    d[0][2] = 0;
    d[0][3] = 0;
    for (int i = 1; i <= n; i++) {
        d[i][0] = ((d[i - 1][1] + d[i - 1][2]) % INF + d[i - 1][3]) % INF;
        d[i][1] = ((d[i - 1][0] + d[i - 1][2]) % INF + d[i - 1][3]) % INF;
        d[i][2] = ((d[i - 1][1] + d[i - 1][0]) % INF + d[i - 1][3]) % INF;
        d[i][3] = ((d[i - 1][1] + d[i - 1][2]) % INF + d[i - 1][0]) % INF;
    }
    cout << d[n][0] << endl;
    return 0;
}