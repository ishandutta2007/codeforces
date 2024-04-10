//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 50;

int a[1 + MAXN], b[1 + MAXN];

void Add(int &x, int y, int n) {
    x += y;
    if (x >= n)
        x -= n;
}

void Subtract(int &x, int y, int n) {
    x -= y;
    if (x < 0)
        x += n;
}

bool Try(int x, int n, int l) {
    int delta = b[x] - a[1];
    for (int i = 1, j = x; i <= n; i++, j++) {
        if (j == n + 1)
            j = 1;
        int y = a[i];
        Add(y, delta, l);
        if (y != b[j])
            return false;
    }
    return true;
}

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (Try(i, n, l)) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}