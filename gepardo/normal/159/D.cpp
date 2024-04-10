#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool t[4000][4000] = {};
int c[4000] = {};

int main()
{
    string s;
    getline(cin, s);
    int n = s.length();
    for (int i = 0; i < n; i++) t[i][i] = true;
    for (int i = 1; i < n; i++) t[i - 1][i] = s[i - 1] == s[i];
    for (int k = 2; k < n; k++)
        for (int i = 0; i < n - k; i++)
            if (s[i] == s[i + k]) t[i][i + k] = t[i + 1][i + k - 1];
    c[n] = 0;
    c[n - 1] = t[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        c[i] = c[i + 1];
        for (int j = i; j < n; j++) c[i] += t[i][j];
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (t[i][j]) res += (long long)c[j + 1];
    cout << res;
}