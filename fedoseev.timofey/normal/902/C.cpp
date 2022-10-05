#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int h;
    cin >> h;
    int n = 0;
    vector <int> a(h + 1);
    for (int i = 0; i <= h; ++i) {
        cin >> a[i];
        n += a[i];
    }
    set <int> s;
    for (int i = 1; i + 1 <= h; ++i) {
        if (a[i] != 1 && a[i + 1] != 1) {
            s.insert(i + 1);
            break;
        }
    }
    if (s.empty()) {
        cout << "perfect" << endl;
        return 0;
    }
    vector <int> d1(n);
    d1[0] = 0;
    int last = 1;
    int k = 1;
    for (int i = 1; i <= h; ++i) {
        for (int j = k; j - k + 1 <= a[i]; ++j) {
            d1[j] = last;
        }
        last += a[i];
        k += a[i];
    }
    vector <int> d2;
    d2 = d1;
    int g = *s.begin();
    int l = 0;
    for (int i = 0; i <= g; ++i) {
        l += a[i];
    }
    l -= 2;
    --d2[l];
    cout << "ambiguous" << endl;
    for (auto e : d1) {
        cout << e << " ";
    }
    cout << endl;
    for (auto e : d2) {
        cout << e << " ";
    }
    cout << endl;
}