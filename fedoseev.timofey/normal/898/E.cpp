#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> square;

const int last = 31623;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i * i <= (int)1e9; ++i) {
        square.push_back(i * i);
    }
    square.push_back(last * last);
    vector <int> dist2;
    vector <int> dist1;
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(square.begin(), square.end(), a[i]) - square.begin();
        if (square[ind] == a[i]) {
            if (a[i] == 0) dist1.push_back(2);
            else dist1.push_back(1);
        }
        else {
            int d = min(square[ind] - a[i], a[i] - square[ind - 1]);
            dist2.push_back(d);
        }
    }
    sort(dist2.rbegin(), dist2.rend());
    sort(dist1.begin(), dist1.end());
    long long ans = 0;
    int cnt = 0;
    int last = -1;
    for (int i = 0; i < dist2.size(); ++i) {
        if (cnt == n / 2) {
            last = i;
            break;
        }
        ++cnt;
    }
    int i = 0;
    if (cnt != n / 2) {
        while (cnt != n / 2) {
            ++cnt;
            ans += dist1[i];
            ++i;
        }
    }
    else {
        for (int i = last; i < dist2.size(); ++i) {
            ans += dist2[i];
        }
    }
    cout << ans << endl;
}