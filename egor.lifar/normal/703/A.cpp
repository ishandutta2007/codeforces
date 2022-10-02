#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>
#include <queue>


using namespace std;


int n;


int main() {
    cin >> n;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            cnt++;
        }
        if (b > a) {
            cnt1++;
        }
    }
    if (cnt == cnt1) {
        cout << "Friendship is magic!^^" << endl;
    } else {
        if (cnt > cnt1) {
            cout << "Mishka" << endl;
        } else {
            cout << "Chris" << endl;
        }
    }
    return 0;
}