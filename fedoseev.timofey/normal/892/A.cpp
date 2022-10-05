#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <pair <long long, long long>> ve(n);
    for (int i = 0; i < n; ++i) {
        long long c;
        cin >> c;
        ve[i].second = c;
    }
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        ve[i].first = x;
    }
    sort(ve.begin(), ve.end());
    long long s = 0;
    for (int i = 0; i < ve.size(); ++i) {
        s += ve[i].second;
    }
    if (ve[n - 1].first + ve[n - 2].first >= s) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}