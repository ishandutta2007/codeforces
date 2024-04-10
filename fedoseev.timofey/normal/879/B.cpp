# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector <long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long maxx = -1;
    for (int i = 0; i < n; ++i) maxx = max(maxx, a[i]);
    long long power = a[0];
    long long cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > power) {
            power = a[i];
            cnt = 1;
        }
        else {
            ++cnt;
            if (cnt >= k) {
                cout << power << endl;
                return 0;
            }
        }
    }
    cout << maxx << endl;
}