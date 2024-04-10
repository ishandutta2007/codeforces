#include <bits/stdc++.h>
using namespace std;

bool z = 0;
int n, m, k;
string s;

int main()
{
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s [i] == '?') z = 1;
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s [i] == s [i + 1] && s [i] != '?') z = 0;
    }
    if (!z) {cout << "No"; return 0;}
    z = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s [i] == '?' && (s [i - 1] == s [i + 1] || s [i - 1] == '?' || s [i + 1] == '?')) z = 1;
    }
    if (s [0] == '?' || s [s.size() - 1] == '?') z = 1;
    if (!z) {cout << "No"; return 0;}
    cout << "Yes";
    return 0;
}