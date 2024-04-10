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


int k = 0;


void get(int n) {
    if (n == 8) {
        cout << "7 * 8 = 56" << endl;
        cout << "6 * 5 = 30" << endl;
        cout << "3 - 4 = -1" << endl;
        cout << "1 - 2 = -1" << endl;
        cout << "30 - -1 = 31" << endl;
        cout << "56 - 31 = 25" << endl;
        cout << "25 + -1 = 24" << endl;  
        for (int i = 0; i < k; i++) {
            cout << "24 * 1 = 24" << endl; 
        }
        return;
    }
    cout << n << " - " << n - 1 << " = " << 1 << endl;
    k++;
    get(n - 2); 
}


bool b = true;


void get1(int n) {
    if (b) {
        cout << "5 - 3 = 2" << endl;
        cout << "2 * 4 = 8" << endl;
        cout << "1 + 2 = 3" << endl;
        cout << "3 * 8 = 24" << endl;
        b = false;
    }
    if (n <= 5) {
        exit(0);
    }
    cout << n << " - " << n - 1 << " = " << 1 << endl;
    cout << "24 * 1 = 24" << endl;
    get1(n - 2); 
}


int main() {
    int n;
    cin >> n;
    if (n >= 4 && n % 2 == 0) {
        cout << "YES" << endl;
        cout << "3 * 4 = 12" << endl;
        cout << "2 * 12 = 24" << endl;
        cout << "24 * 1 = 24" << endl;
        for (int i = n; i > 4; i--) {
            if (i % 2 == 0) {
                cout << i << " - " << i - 1 << " = " << 1 << endl;
                cout << "24 * 1 = 24" << endl;
            }
        }
        return 0;
    }
    if (n < 5) {
        cout << "NO" << endl;
        return 0; 
    }
    cout << "YES" << endl;
    if (n % 2 == 0) {
        get(n);
    } else {
        get1(n);
    }
    return 0;
}