#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main()
{
    ios_base::sync_with_stdio(false);

    int mx = 0;
    string s;
    while (getline(cin, s)) {
        mx = max(mx, (int)s.size());
        v.push_back(s);
    }
    for (int i = 0; i < mx + 2; ++i)
        cout << "*";
    cout << "\n";
    int odd = 0;
    for (string & s : v) {
        cout << "*";
        for (int j = (mx - s.size() + (mx % 2 != s.size() % 2) * odd) / 2; j--; )
            cout << " ";
        cout << s;
        for (int j = (mx - s.size() + (mx % 2 != s.size() % 2) * (1 - odd)) / 2; j--; )
            cout << " ";
        cout << "*\n";
        if (mx % 2 != s.size() % 2)
            odd ^= 1;
    }for (int i = 0; i < mx + 2; ++i)
        cout << "*";

    return 0;
}