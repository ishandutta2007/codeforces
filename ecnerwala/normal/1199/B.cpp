#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double H, L; cin >> H >> L;
    cout << fixed << setprecision(10) << (L*L/H-H)/2 << '\n';
}