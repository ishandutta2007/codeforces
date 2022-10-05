#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a %= b;
    a *= 10;
    set <int> f;
    int cnt = 1;
    bool fl = true;
    while (a / b != c && f.find(a) == f.end()) {
        ++cnt;
        f.insert(a);
        a %= b;
        a *= 10;
    }
    if (a / b == c) {
        cout << cnt << endl;
    }
    else {
        cout << -1 << endl;
    }
}