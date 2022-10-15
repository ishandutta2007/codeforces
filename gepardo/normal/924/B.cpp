#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef long double ld;

ld ans = -1;

vector <int> a;
int n, u;

void add(int k, int j) {
    ld x = a[k] - a[j];
    ld y = a[k] - a[j - 1];
    ans = max(ans, x / y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> u; a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = 2;
    for (int i = 1; i < n; i++) {
        while ((pos < n) && (a[pos] - u <= a[i - 1])) pos++;
        pos--;
        //cout << i << " " << pos << endl;
        if (pos == i) {
            pos++;
        } else {
            add(pos, i);
        }
    }
    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(9) << ans << endl;
    }
    return 0;
}