#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        long long X, Y; cin >> X >> Y;
        cout << (X-Y==1?"NO":"YES") << '\n';
    }
}