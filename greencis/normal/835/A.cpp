#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll s, v1, v2, t1, t2;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s >> v1 >> v2 >> t1 >> t2;
    ll a1 = t1 + s * v1 + t1;
    ll a2 = t2 + s * v2 + t2;
    puts(a1 < a2 ? "First" : a1 > a2 ? "Second" : "Friendship");

    return 0;
}