#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int c[100];
int d[100];


int main(){
    int m, x, y;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    cin >> x >> y;
    for (int i = 0; i < m; i++) {
        d[i] = (i > 0 ? d[i - 1]: 0) + c[i];
    }
    for (int i = 1; i < m; i++) {
        if (d[i - 1] >= x && d[i - 1] <= y && d[m - 1] - d[i - 1] >= x && d[m - 1] - d[i - 1] <= y) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}