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
    int k = 0, l = 0, m = 0;
    for (int i = 1; i <= 6; i++) {
        if(abs(i - a) > abs(i - b)) {
            l++;
        }
        if (abs(i - a) < abs(i - b)) {
            k++;
        }
        if(abs(i - a) == abs(i - b)) {
            m++;
        }
    }
    cout << k << ' ' << m << ' ' << l << endl;
    return 0;
}