#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n;
int a = 0;
int b = 0;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 25) {
            a++;
        }
        if (c == 50) {
            b++;
        }
        if (c == 50) {
            if (a == 0) {
                cout << "NO" << endl;
                return 0;
            } else {
                a--;
            }
        }
        if (c == 100) {
            if (b >= 1 && a >= 1) {
                b--;
                a--;
            } else {
                    if (a >= 3) {
                        a-= 3;
                    } else {
                        cout << "NO" << endl;
                        return 0;
                    }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}