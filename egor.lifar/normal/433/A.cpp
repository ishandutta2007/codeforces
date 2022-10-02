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
#include <assert.h>


using namespace std;

int n;
int a, b;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 100) {
            a++;
        } else {
            b++;
        }
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i * 100 + j * 200 == (a - i) * 100 + (b - j) * 200) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}