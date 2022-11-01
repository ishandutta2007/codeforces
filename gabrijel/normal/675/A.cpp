#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    if (c == 0 && a == b) {cout << "YES"; return 0;}
    else if (c == 0) {cout << "NO"; return 0;}
    if (c > 0 && a > b)
    {
        cout << "NO";
    }
    else if (c > 0)
    {
        if ((b - a) % c == 0) cout << "YES";
        else cout << "NO";
    }
    if (c < 0 && b > a)
    {
        cout << "NO";
    }
    else if (c < 0)
    {
        if ((a - b) % c == 0) cout << "YES";
        else cout << "NO";
    }
    return 0;
}