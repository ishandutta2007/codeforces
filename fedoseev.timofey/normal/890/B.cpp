#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <tuple>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> last(1e6, 1e9);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        last[x] = i;
    }
    int ans = 1e9;
    int num = -1;
    for (int i = 0; i < 1e6; ++i) {
        if (last[i] < ans) {
            ans = last[i];
            num = i;
        }
    }
    cout << num << endl;
}