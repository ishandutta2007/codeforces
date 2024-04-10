# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> ans;
    for (int i = 2; i <= n; i += 2) ans.push_back(i);
    for (int i = 1; i <= n; i += 2) ans.push_back(i);
    for (int i = 2; i <= n; i += 2) ans.push_back(i);
    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem << " ";
    }
}