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


int n;
int h[2501], w[2501];
bool bh[51], bw[51];


int main() {   
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        scanf("%d %d", &h[i], &w[i]);
        h[i]--;
        w[i]--;
        if (!bh[h[i]] && !bw[w[i]]) {
            bh[h[i]] = true;
            bw[w[i]] = true;
            cout << i + 1 << endl;
        }
    }
    return 0;
}