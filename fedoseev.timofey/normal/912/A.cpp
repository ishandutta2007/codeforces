#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    ll x, y, z;
    cin >> x >> y >> z;
    ll cA = 2 * x + y;
    ll cB = y + 3 * z;
    ll Na = max(0LL, cA - A);
    ll Nb = max(0LL, cB - B);
    cout << Na + Nb << endl;
}