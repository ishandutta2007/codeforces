#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>


using namespace std;


string s, s1;
int k = 0;
int a, b;


int get(int i, int r) {
    if (i == k) {
        if (r == b) {
            return 1;
        }
        return 0;
    }
    return get(i + 1, r + 1) + get(i + 1, r - 1);
}


int main() {
    cin >> s >> s1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            a++;
        } else {
            a--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] == '+') {
            b++;
        } else {
            if (s1[i] == '-') {
                b--;
            } else {
                k++;
            }
        }
    }
    double l = 1;
    double p = 0;
    for (int i = 0; i < k; i++) {
        l*= 2;
    }
    p = get(0, a);
    printf("%.10lf\n", p / l);
    return 0;
}