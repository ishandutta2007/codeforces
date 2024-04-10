#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int a, b, c;


bool prosto(int t) {
    return (t + c)* b >= c * a;
}


int main() {
    cin >> a >> b >> c;
    int l = 1;
    int r = (a * c + b - 1) / b;
    while (l != r) {
        int m = (l + r) / 2;
        if (prosto(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;
    return 0;
}