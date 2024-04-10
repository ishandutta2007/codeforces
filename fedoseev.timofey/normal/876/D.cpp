# include <iostream>
# include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector <bool> is(n + 1);
    int last = n;
    cout << 1 << " ";
    for (int i = 0; i < n; ++i) {
        is[p[i]] = true;
        while (is[last]) --last;
        cout << i - n + last + 2 << " ";
    }
    cout << endl;
    return 0;
}