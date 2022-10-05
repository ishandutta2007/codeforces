# include <iostream>
# include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num = 0;
    vector <int> ans;
    for (int i = n - 1000; i < n; ++i) {
        int tmp = i;
        int k = i;
        while (k > 0) {
            tmp += k % 10;
            k /= 10;
        }
        if (tmp == n) {
            ++num;
            ans.push_back(i);
        }
    }
    cout << num << endl;
    for (auto &elem : ans) {
        cout << elem << endl;
    }
}