#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
 
 
using namespace std;
 

int n, l, v1, v2, k;


bool get(double x) {
    double curtime = 0.0;
    double posBus = 0.0;
    for (int i = 0; i < (n + k - 1) / k; i++) {
        double posPeople = curtime * v1;
        if (posPeople > l) {
            return 0;
        }
        double timer = (posBus - posPeople) / double(v1 + v2);
        curtime += timer;
        posPeople += timer * v1;
        posBus -= timer * v2;
        if (l - posPeople < x) {
            return 0;
        }
        curtime += x / double(v2);
        posBus += x;
    }
    return 1;
}


int main() {
    cin >> n >> l >> v1 >> v2 >> k;
    if (v1 > v2) {
        printf("%.10lf\n", double(l) / double(v1));
    } else {
        double L = 0.0;
        double R = l;
        for (int i = 0; i < 120; i++) {
            double M = (L + R) / 2.0;
            if (get(M)) {
                L = M;
            } else {
                R = M;
            }
        }
        printf("%.10lf\n", double(l - L) / double(v1) + L / double(v2));
    }
    return 0;
}