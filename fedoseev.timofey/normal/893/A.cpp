#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> pl;
    int s = 3;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (s == x) {
            cout << "NO" << endl;
            return 0;
        }
        s = 6 - s - x;
    }
    cout << "YES" << endl;
}