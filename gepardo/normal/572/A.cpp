#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int q, w;
    cin >> q >> w;
    vector <int> a(q), b(w);
    int m, k; cin >> m >> k;
    for (int i = 0; i < q; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];
    if (a[m - 1] < b[w - k]) cout << "YES"; else cout << "NO";
}