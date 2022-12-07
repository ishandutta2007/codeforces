#include <iostream>

using namespace std;

int main(void)
{
    int n, a, b, s[2000], i, j;
    cin >> n >> a >> b;
    for (i = 0; i < n; ++i)
        cin >> s[i];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n - 1; ++j)
            if (s[j] < s[j + 1])
            {
                s[j] ^= s[j + 1];
                s[j + 1] = s[j] ^ s[j + 1];
                s[j] ^= s[j + 1];
            }
    cout << s[a - 1] - s[a];
    return 0;
}