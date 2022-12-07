#include <iostream>

using namespace std;

int nod(int a, int b)
{
    if (b > a)
        return nod(b, a);
    if (!b)
        return a;
    return nod(b, a % b);
}

int beats(char a, char b)
{
    if ((a == 'R') && (b == 'R')) return 0;
    if ((a == 'R') && (b == 'S')) return 1;
    if ((a == 'R') && (b == 'P')) return 2;
    if ((a == 'S') && (b == 'R')) return 2;
    if ((a == 'S') && (b == 'S')) return 0;
    if ((a == 'S') && (b == 'P')) return 1;
    if ((a == 'P') && (b == 'R')) return 1;
    if ((a == 'P') && (b == 'S')) return 2;
    if ((a == 'P') && (b == 'P')) return 0;
    return 0;
}

int main(void)
{
    int n, a1 = 0, a2 = 0, i;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int nok = (s1.length() * s2.length()) / nod(s1.length(), s2.length());
    for (i = 0; i < nok; ++i)
        switch (beats(s1[i % s1.length()], s2[i % s2.length()]))
        {
            case 1:
                ++a2;
                break;
            case 2:
                ++a1;
                break;
            default:
                ;
        }
    a1 *= n / nok;
    a2 *= n / nok;
    n %= nok;
    for (i = 0; i < n; ++i)
        switch (beats(s1[i % s1.length()], s2[i % s2.length()]))
        {
            case 1:
                ++a2;
                break;
            case 2:
                ++a1;
                break;
            default:
                ;
        }
    cout << a1 << ' ' << a2;
    return 0;
}