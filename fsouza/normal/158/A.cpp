#include <iostream>
#include <cstdio>

using namespace std;

int vals[55];

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    k--;

    for (int i = 0; i < n; i++)
        scanf("%d", &vals[i]);

    int last = -1;

    while ((last+1) < n && vals[last+1] >= vals[k] && vals[last+1] > 0)
        last ++;

    printf("%d\n", last+1);

    return 0;
}