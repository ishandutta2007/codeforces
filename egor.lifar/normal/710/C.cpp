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
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
int even[50][50];


int main() {
    cin >> n;
    if (n % 2 == 1) {
        if (n % 4 == 3) {
            for (int i = 1; i <= n / 2; i+= 2) {
                for (int j = 0; j <= i; j++) {
                    even[i][j] = 1;
                    even[j][i] = 1;
                }
            }
        } else {
            for (int i = 0; i <= n / 2; i+= 2) {
                for (int j = 0; j <= i; j++) {
                    even[i][j] = 1;
                    even[j][i] = 1;
                }
            }
        }
        if (n % 2 == 1) {
            even[n / 2][n / 2] = 1;
        }
        for (int i = n / 2 + 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                even[j][i] = even[j][n - i - 1];
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                even[i][j] = even[n - i - 1][j];
            }
        }
        vector<int> v, v1;
        for (int i = 1; i <= n * n; i++) {
            if (i % 2) {
                v.push_back(i);
            } else {
                v1.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               // cout << even[i][j] << ' ';
                if (even[i][j]) {
                    cout << v.back() << ' ';
                    v.pop_back(); 
                } else {
                    cout << v1.back() << ' ';
                    v1.pop_back();
                }
            }
            cout << endl;
        }
    }
    return 0;
}