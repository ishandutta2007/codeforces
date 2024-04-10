#include <bits/stdc++.h>
using namespace std;

int n, k;
string s, rj = "";
set <char> slova;

string dop(int kol)
{
    string ret = "";
    for (int kon = 0; kon < kol; kon++) ret += *slova.begin();
    return ret;
}

int main()
{
    scanf("%d%d", &n, &k);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        slova.insert(s [i]);
    }
    if (k > n)
    {
        cout << s + dop(k - n);
        return 0;
    }
    char najveci = *(--slova.end());
    if (k == 1)
    {
        cout << *slova.upper_bound(s [0]);
        return 0;
    }
    char poc = s [0];
    rj = poc;
    for (int i = k - 1; i >= 1; i--)
    {
        if (s [i] != najveci)
        {
            cout << rj + s.substr(1, i - 1) + *slova.upper_bound(s [i]) + dop(k - 1 - i);
            return 0;
        }
    }
    rj = *slova.upper_bound(poc);
    cout << rj + dop(k - 1);
    return 0;
}