#include <iostream>
using namespace std;

int main()
{
    long long n, sum = 0, ns = 1, nums = 9;
    cin >> n;
    for (;;)
    {
        if (n > nums)
        {
            sum += nums * ns;
            n -= nums;
        }
        else
        {
            sum += n * ns;
            break;
        }
        nums *= 10;
        ns++;
    }
    cout << sum;
}