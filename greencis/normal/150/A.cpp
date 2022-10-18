#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll q,qq;
vector<ll> v;

int main()
{
    cin >> q; qq = q;
    for (ll i = 2; i * i <= q; ++i) {
        while (q % i == 0) v.push_back(i), q /= i;
    }
    if (q != 1) v.push_back(q);
    if (v.size() <= 1) { cout << "1\n0"; }
    else if (v.size() == 2) { cout << 2; }
    else { cout << 1 << "\n" << v[0] * v[1]; }

    return 0;
}