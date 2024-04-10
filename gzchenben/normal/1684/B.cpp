#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, a, b, c;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d %d %d\n", a + b + c, b + c, c);
    }
}