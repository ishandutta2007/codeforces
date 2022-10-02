#include <iostream>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>


using namespace std;



int main() {
    vector<int> p;
    for (int i = 2; i <= 47; i++) {
        bool b = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                b = 0;
                break;
            }
        }
        if (b) {
            p.push_back(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        cout << p[i] << endl;
        string ans;
        cin >> ans;
        if (ans == "no") {
            continue;
        }
        cnt++;
        if (cnt == 2) {
            cout << "composite" << endl;
            return 0;
        }
        if (p[i] * p[i] < 100) {
            cout << p[i] * p[i] << endl;
            cin >> ans;
            if (ans == "yes") {
                cout << "composite" << endl;
                return 0;
            }
        }
    }
    cout << "prime" << endl;
    return 0;   
}