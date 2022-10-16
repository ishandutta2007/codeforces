#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int ar,as,ap,br,bs,bp;
    cin >> ar >> as >> ap >> br >> bs >> bp;

    cout << max({ar+bs, as+bp, ap+br, n}) - n << " ";
    cout << min(ar,bs) + min(as,bp) + min(ap,br);
    return 0;
}