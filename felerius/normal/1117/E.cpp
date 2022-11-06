#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string t;
    cin >> t;

    vector<array<int, 3>> m(t.size());
    string q(t.size(), ' ');
    string a;

    for (size_t i = 0; i < q.size(); ++i) {
        q[i] = 'a' + (i % 26);
    }
    cout << "? " << q << '\n';
    cout.flush();
    cin >> a;
    for (size_t i = 0; i < q.size(); ++i) {
        m[i][0] = a[i] - 'a';
    }

    for (size_t i = 0; i < q.size(); ++i) {
        q[i] = 'a' + ((i / 26) % 26);
    }
    cout << "? " << q << '\n';
    cout.flush();
    cin >> a;
    for (size_t i = 0; i < q.size(); ++i) {
        m[i][1] = a[i] - 'a';
    }

    for (size_t i = 0; i < q.size(); ++i) {
        q[i] = 'a' + ((i / (26*26)) % 26);
    }
    cout << "? " << q << '\n';
    cout.flush();
    cin >> a;
    for (size_t i = 0; i < q.size(); ++i) {
        m[i][2] = a[i] - 'a';
    }

    for (size_t i = 0; i < q.size(); ++i) {
        q[m[i][2] * 26 * 26 + m[i][1] * 26 + m[i][0]] = t[i];
    }

    cout << "! " << q << '\n';

    return 0;
}