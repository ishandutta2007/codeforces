#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


int n;
string s;


int main() {
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + i * 4 >= n) {
                continue;
            }  
            bool b = true;
            for (int k = 0; k < 5; k++) {
                if (s[j + i * k] != '*') {
                    b = false;
                }
            }
            if (b) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}