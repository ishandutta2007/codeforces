
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s[0] != s.back()) s[0] = s.back();
        cout << s << "\n";
    }
    return 0;
}