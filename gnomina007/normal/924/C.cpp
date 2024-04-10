#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<int> m (n);

    for (auto &it : m)
        cin >> it;

    vector<int> all (n);
    all[0] = m[0];

    for (int i = 1; i < all.size (); i++)
        all[i] = max (all[i - 1], m[i]);

    for (int i = all.size () - 1; i > 0; i--)
        all[i - 1] = max (all[i - 1], all[i] - 1);

    long long sum = 0;

    for (int i = 0; i < all.size (); i++)
        sum += all[i] - m[i];

    cout << sum << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}