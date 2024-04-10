#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

int gcd(int x, int y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int mult = lcm(x, y);
    cout << b / mult - (a - 1) / mult << endl;
    return 0;
}