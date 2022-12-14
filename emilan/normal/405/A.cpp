#include <bits/stdc++.h>
using namespace std;
#define sv(x) int sv_##x; cin >> sv_##x; while (sv_##x--)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> col;

    sv() {
        int a;
        cin >> a;
        col.push_back(a);
    }

    sort(begin(col), end(col));

    for (auto& i : col)
        cout << i << ' ';

    return 0;
}