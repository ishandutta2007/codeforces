#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << (n % 4 == 1 || n % 4 == 2 ? 1 : 0) << endl;
}