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
#include <iomanip>

#include <cassert>
#include <cmath>

using namespace std;

void foo (string &str)
{
    for (auto &it : str)
    {
        if (it == '0')
            it = 'o';
        if (it == 'I' || it == 'i' || it == '1')
            it = 'l';

        if ('A' <= it && it <= 'Z')
            it += 'a' - 'A';
    }
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    string str;

    cin >> str;

    foo (str);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string tmp;

        cin >> tmp;

        foo (tmp);

        if (tmp == str)
        {
            cout << "No" << endl;

            return;
        }
    }

    cout << "Yes" << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

#ifdef LOCAL
    cout << "clock: " << clock () << endl;
#endif // LOCAL

    return 0;
}