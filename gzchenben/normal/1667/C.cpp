#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    int B1 = (n - 1) / 3;
    int B2 = B1 + 1;
    printf("%d\n", B1 + B2 + (n % 3 == 0 ? 1 : 0));
    for (int i = 1; i <= B1; i++)
    {
        printf("%d %d\n", i, B1 + 1 - i);
    }
    for (int i = 1; i <= B2; i++)
    {
        printf("%d %d\n", B1 + i, B1 + B2 + 1 - i);
    }
    if (n % 3 == 0)
    {
        printf("%d %d\n", B1 + B2 + 1, B1 + B2 + 1);
    }
    return 0;
}