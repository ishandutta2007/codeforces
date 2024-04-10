#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    set <string> yet;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (!yet.count(s)) {
            cout << "NO" << endl;
            yet.insert(s);
        }
        else
            cout << "YES" << endl;
    }
}