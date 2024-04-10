#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n;
pair<int, int> p[100001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    sort(p, p + n);
    cout << n - n / 2 << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << p[i].second << ' ';
        }
    }
    cout << endl;
    cout << n / 2 << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            cout << p[i].second << ' ';
        }
    }
    cout << endl;
    return 0;
}