#include <bits/stdc++.h>
using namespace std;
 
int qry(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x; cin >> x; return x;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int p = qry(1, n);
    if (p != 1 && qry(1, p) == p) {
        int x = 1;
        for (int i = 1<<20; i > 0; i /= 2)
            if (x+i < p && qry(x+i, p) == p) x += i;
        cout << "! " << x << endl;
    } else {
        int x = n;
        for (int i = 1<<20; i > 0; i /= 2)
            if (x-i > p && qry(p, x-i) == p) x -= i;
        cout << "! " << x << endl;
    }
}