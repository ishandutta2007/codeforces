#include <iostream>

using namespace std;

int main(void)
{
    int p[50], t;
    int n, k, i, j, answ;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> p[i] >> t;
        p[i] = p[i] * 500 + (100 - t);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (p[j] < p[j + 1])
            {
                p[j] ^= p[j + 1];
                p[j + 1] = p[j] ^ p[j + 1];
                p[j] ^= p[j + 1];
            }
    answ = 1;
    for (j = k; j < n; j++)
        if (p[j] == p[k - 1])
            answ++;
        else
            break;
    for (j = k - 2; j >= 0; j--)
        if (p[j] == p[k - 1])
            answ++;
        else
            break;
    cout << answ;
    return 0;
}