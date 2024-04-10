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


int main() {
    int a, b;
    cin >> a >> b;
    long long s = a;
    long long l = a;
    while(l >= b) {
        s += l / b;
        l = l % b + l / b;
    }
    cout << s << endl;
    return 0;
}