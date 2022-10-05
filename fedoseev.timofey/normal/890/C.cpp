#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <tuple>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    map <int, int> last;
    last[0] = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (last.count(t[i])) {
            int r = last[t[i]];
            last.erase(t[i]);
            last[i + 1] = r;
        }
        else {
            last[i + 1] = cnt;
            ++cnt;
        }
    }
    cout << cnt << endl;
}