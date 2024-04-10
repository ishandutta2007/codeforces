#include <iostream>
#include <vector>

using namespace std;

#define int long long

vector <int> p, x, y, a, b;
int n, m;

void init(int n) { p.resize(n, -1); }

int findSet(int n) {
    return (p[n] < 0) ? (n) : (p[n] = findSet(p[n]));
}

bool unite(int a, int b) {
    a = findSet(a), b = findSet(b);
    if (a != b) p[b] = a;
}

main() {
    cin >> n >> m; init(n);
    a.resize(n, 0); b.resize(n, 0);
    x.resize(m); y.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        unite(x[i] - 1, y[i] - 1);
    }

    for (int i = 0; i < n; i++)
        a[findSet(i)]++;
    for (int i = 0; i < m; i++)
        b[findSet(x[i] - 1)]++;
    /*
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    */
    for (int i = 0; i < n; i++)
        if ((a[i] * (a[i] - 1)) / 2 != b[i]) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    return 0;
}