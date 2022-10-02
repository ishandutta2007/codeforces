#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


int n;


bool prost(int a) {
    for (int j = 2; j <= (int)sqrt(n); j++) {
        if (a % j == 0) {
            return false;
        }
    }
    return true;
}


int main() {   
    cin >> n;
    if (n == 3) {
        cout << 1 << endl;
        cout << 3 << endl;
        return 0;
    }
    if (n == 5) {
        cout << 1 << endl;
        cout << 5 << endl;
        return 0;
    }
    if (n == 7) {
        cout << 1 << endl;
        cout << 7 << endl;
        return 0;
    }
    if (n == 9) {
        cout << 2 << endl;
        cout << 7 << ' ' << 2 << endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(3);
    n -= 3;
    for (int i = 2; i <= min(n, 100000); i++) {
        if (prost(i)) {
            if (prost(n - i)) {
                ans.push_back(i);
                ans.push_back(n - i);
                break;
            }
        }
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}