#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin() (x).end()

using namespace std;

int main(){

    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;
    vector<int> a(n);
    int x = 0, y = 0;
    do {
        a[x] = y;
        x = (x + dx) % n;
        y = (y + dy) % n;
    } while (x);
    vector<int> d(n);
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        int z = y - a[x];
        if (z < 0) z += n;
        d[z]++;
    }
    cout << 0 << " " << (max_element(d.begin(), d.end()) - d.begin()) << "\n";

    return 0;
}