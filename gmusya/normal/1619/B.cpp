#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e9;

#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int> squares, cubes, square_cubes;
    for (int i = 1; i * i <= MAX_N; ++i) {
        squares.push_back(i * i);
    }
    for (int i = 1; i * i * i <= MAX_N; ++i) {
        cubes.push_back(i * i * i);
    }
    for (int i = 1; i * i * i * i * i * i <= MAX_N; ++i) {
        square_cubes.push_back(i * i * i * i * i * i);
    }
    while (t--) {
        int l, r;
        l = 1;
        cin >> r;
        int a = upper_bound(all(squares), r) - lower_bound(all(squares), l);
        int b = upper_bound(all(cubes), r) - lower_bound(all(cubes), l);
        int c = upper_bound(all(square_cubes), r) - lower_bound(all(square_cubes), l);
        cout << a + b - c << '\n';
    }
    return 0;
}