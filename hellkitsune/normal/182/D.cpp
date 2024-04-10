#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    string s[2];
    int k[2];
    k[0] = 1;
    k[1] = 1;
    cin >> s[0] >> s[1];
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j < (int)s[i].length(); ++j)
            if (s[i][j] != s[i][j - k[i]])
                if (s[i][j] == s[i][0])
                    k[i] = j;
                else
                    k[i] = j + 1;
    for (int i = 0; i < 2; ++i)
        if (s[i].length() % k[i] > 0)
            k[i] = s[i].length();
    if (k[0] != k[1])
    {
        cout << 0;
        return 0;
    }
    if (s[0].substr(0, k[0]) != s[1].substr(0, k[0]))
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < 2; ++i)
        k[i] = s[i].length() / k[i];
    int g = gcd(k[0], k[1]), ans = 1, cur;
    for (int i = 2; i <= g; ++i)
    {
        cur = 1;
        while (g % i == 0)
        {
            g /= i;
            ++cur;
        }
        ans *= cur;
    }
    cout << ans;
    return 0;
}