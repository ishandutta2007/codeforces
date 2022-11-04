// LOL
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
int main()
{
    string s;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == 'a')
            r = i, c ++;
    if ((n - c) % 2 == 1)
        return !printf(":(");
    t = (n - c) / 2;
    if (t + c <= r)
        return !printf(":(");
    string ss = "", tt = "";
    for (int i = 0; i < t + c; i++)
        if (s[i] != 'a')
            ss += s[i];
    for (int i = t + c; i < n; i++)
        tt += s[i];
    if (ss != tt)
        return !printf(":(");
    for (int i = 0; i < t + c; i++)
        cout << s[i];
    return (0);
}