#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    for (volatile int i = 0; i < (int)1e9; i++);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}