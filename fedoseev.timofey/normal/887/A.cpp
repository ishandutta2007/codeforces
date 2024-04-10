#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    for (auto elem : s) {
        if (elem == '1') ++cnt1;
        else if (cnt1 >= 1) ++cnt0;
    }
    if (cnt0 >= 6) cout << "Yes" << endl;
    else cout << "No" << endl;
}