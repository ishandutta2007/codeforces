#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n, m;


int main() {
    cin >> n >> m;
    cout << min(n, m) + 1 << endl;
    for (int i = 0; i <= min(n, m); i++) {
        cout << i << ' ' << min(n, m) - i << endl;
    }
    return 0;
}