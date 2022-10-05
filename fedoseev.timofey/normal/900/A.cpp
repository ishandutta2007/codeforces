#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < 0) ++cnt1;
        else ++cnt2;
    }
    if (cnt1 <= 1 || cnt2 <= 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}