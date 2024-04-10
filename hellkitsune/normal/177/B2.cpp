#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    long long answ = 1;
    for (int i = 2; i < sqrt(n) + 1; ++i)
        while (n % i == 0)
        {
            answ += n;
            n /= i;
        }
    if (n > 1)
        answ += n;
    cout << answ;
    return 0;
}