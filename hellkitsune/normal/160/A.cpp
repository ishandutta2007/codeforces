#include <stdio.h>

using namespace std;

int main()
{
    int n, i, k, sum = 0, count;
    int b[100] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        ++b[k - 1];
        sum += k;
    }
    sum = sum / 2 + 1;
    count = 0;
    for (i = 99; i >= 0; i--)
        while (b[i] > 0)
        {
            sum -= i + 1;
            --b[i];
            count++;
            if (sum <= 0)
            {
                printf("%d", count);
                return 0;
            }
        }
    return 0;
}