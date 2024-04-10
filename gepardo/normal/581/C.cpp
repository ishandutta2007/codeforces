#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k, a, sum = 0, qval[11] = {}, sval[10] = {};
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += (a / 10);
        sval[a % 10]++;
        if (a % 10 == 0) qval[a / 10]++; else qval[(a / 10) + 1]++;
    }
    for (int i = 9; i > 0; i--)
    {
        sval[i] *= (10 - i);
        if (k >= sval[i])
        {
            sum += sval[i] / (10 - i);
            k -= sval[i];
        }
        else
        {
            sum += k / (10 - i);
            k = 0;
            break;
        }
    }
    if (k >= 0)
    {
        k /= 10;
        for (int i = 0; i < 10; i++)
        {
            if (k >= qval[i])
            {
                sum += qval[i];
                qval[i + 1] += qval[i];
                k -= qval[i];
            }
            else
            {
                sum += k;
                qval[i + 1] += k;
                k = 0;
                break;
            }
        }
    }
    cout << sum << endl;
}