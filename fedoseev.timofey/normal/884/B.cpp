# include <set>
# include <iostream>
# include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        cnt += y;
    }
    cnt += n - 1;
    if (cnt == x) cout << "YES" << endl;
    else cout << "NO" << endl;
}