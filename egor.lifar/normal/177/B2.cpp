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


bool prosto(int x) {
    bool b = true;
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            b = false;
            break;
        }
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    long long s = n;
    while (n != 1) {
        if (prosto(n)) {
            s += 1;
            break;
        }
        int i = 2;
        while (n % i != 0) {
            i++;
        }
        n = n / i;
        s += n;
    }
    cout << s << endl;
    return 0;
}