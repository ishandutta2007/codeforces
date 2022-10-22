#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << min({ (a - (p % a)) % a,(b - (p % b)) % b, (c - (p % c)) % c}) << "\n";
    }

    return 0;
}