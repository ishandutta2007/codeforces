#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n, x;
vector<int> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x, v.push_back(x);
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (gcd(v[i], v[i + 1]) != 1) {
            v.insert(v.begin() + i + 1, 1);
        }
    }
    cout << v.size() - n << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    return 0;
}