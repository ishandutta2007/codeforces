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


using namespace std;


int unzero(int x) {
    vector<int> v;
    while(x > 0) {
        if (x % 10 != 0) {
            v.push_back(x % 10);
        }
        x = x / 10;
    }
    reverse(v.begin(), v.end());
    int a = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        a *= 10;
        a += v[i];
    }
    return a;
}

int main() {
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    a = unzero(a);
    b = unzero(b);
    c = unzero(c);
    if (a + b == c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}