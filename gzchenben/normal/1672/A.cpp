#include <cstdio>
using namespace std;
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x - 1;
        }
        printf(sum % 2 == 0 ? "maomao90\n" : "errorgorn\n");
    }
}