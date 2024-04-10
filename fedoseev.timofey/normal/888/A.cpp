#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) if ((a[i - 1] < a[i] && a[i + 1] < a[i]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) ++cnt;
    cout << cnt << endl;
}