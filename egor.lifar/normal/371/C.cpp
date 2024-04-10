#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


string a;
long long b, s, c;
long long nb, ns, nc;
long long pb, ps, pc;
long long rub;


bool get(long long m) {
    long long ans = 0;
    if (b * m > nb) {
        ans += (b * m - nb) * pb;
    }
    if (s * m > ns) {
        ans += (s * m - ns) * ps;
    }
    if (c * m > nc) {
        ans += (c * m - nc) * pc;
    }
    return ans <= rub;
}


int main() {
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'B'){
            b++;
        }
        if (a[i] == 'S'){
            s++;
        }
        if (a[i] == 'C'){
            c++;
        }
    }
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rub;
    long long l = 0;
    long long r = rub + 100;
    while (l != r) {
        long long m = (l + r + 1) / 2;
        if (get(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << endl;
    return 0;
}