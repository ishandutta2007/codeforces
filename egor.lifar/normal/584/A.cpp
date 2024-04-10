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


int n, t;


int main() {   
    cin >> n >> t;
    if (n == 1 && t == 10) {
        cout << -1 << endl;
        return 0;
    }
    if (t == 10) {
        cout << 1;
        for (int i = 0; i < n - 1; i++) {
            cout << 0;
        }
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << t;
    }
    cout << endl;
    return 0;
}