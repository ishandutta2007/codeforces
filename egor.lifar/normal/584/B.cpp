#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


#define M 1000000007


int n;
int d[100001][2];


int main() {   
    cin >> n;
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        d[i + 1][0] += (1LL * 27 * d[i][0]) % M;
        d[i + 1][0] %= M;
        d[i + 1][1] += (1LL * 20 * d[i][0]) % M;
        d[i + 1][1] %= M;
        d[i + 1][1] += (1LL * 7 * d[i][1]) % M;
        d[i + 1][1] %= M;
    }
    cout << d[n][1] << endl;
    return 0;
}