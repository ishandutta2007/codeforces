# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a.begin(), a.end());
    for (auto elem : b) {
        cout << upper_bound(a.begin(), a.end(), elem) - a.begin() << " ";
    }
}