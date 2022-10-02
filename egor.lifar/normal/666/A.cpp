#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


bool can[10001][4];


int main(){
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = n - 1; i >= 0; i--) {  
        for (int j = 2; j <= 3; j++) {
            if (n - i < j) {
                continue;
            }
            int ni = i + j;
            if (ni == n) {
                can[i][j] = 1;
                continue;
            }
            for (int k = 2; k <= 3; k++) {
                if (k != j) { 
                    can[i][j] = max(can[i][j], can[ni][k]);
                } else {
                    string a;
                    for (int g = i; g < ni; g++) {
                        a += s[g];
                    }
                    string b;
                    for (int g = ni; g < ni + k; g++) {
                        b += s[g];
                    }
                    if (a != b) {
                        can[i][j] = max(can[i][j], can[ni][k]);
                    }
                }
            }
        }
    }
    set<string> ss;
    for (int i = 5; i < n; i++) {
        for (int j = i + 1; j <= i + 2 && j < n; j++) {
            string a;
            for (int k = i; k <= j; k++) {
                a += s[k];
            }
            if (j + 1 == n) {
                ss.insert(a);
                continue;
            }
            for (int k = 2; k <= 3; k++) {
                if (!can[j + 1][k]) {
                    continue;
                }
                string b;
                for (int g = j + 1; g <= j + k; g++) {
                    b += s[g];
                }
                if (a != b) {
                    ss.insert(a);
                    break;
                }
            }
        }
    }
    cout << (int)ss.size() << endl;
    for (auto x: ss) {
        cout << x << endl;
    }
    return 0;
}