#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;



int d[2100002];
int d1[2100002];
bool b[2100002];


bool good(int a) {
    vector<int> v;
    while (a > 0) {
        v.push_back(a % 10);
        a /= 10;
    }   
    for (int j = 0; j < (int)v.size(); j++) {
        if (v[j] != v[(int)v.size() - 1 - j]) {
            return false;
        }
    }
    return true;
}



int main() {
    int p, q;
    cin >> p >> q;
    for (int i = 1; i <= 2000000; i++) {
        d[i] = d[i - 1];
        if (good(i)) {
            d[i]++;
        }
    }
  //  cout << "ooa" << endl;
    b[1] = true;
    for (int j = 2; j <= 2000000; j++) {
        if (!b[j]) {
            if (2000000 / j < j) {
                continue;
            }
            for (int g = j * j; g <= 2000000; g+= j) {
                b[g] = true;
            }
        }
    }
  //  cout << "opa" << endl;
    for (int i = 1; i <= 2000000; i++) {
        d1[i] = d1[i - 1];
        if (!b[i]) {
            d1[i]++;
        }
    }
    for (int i = 2000000; i >= 1; i--) {
        if (1LL * d1[i] * q <= 1LL * p * d[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}