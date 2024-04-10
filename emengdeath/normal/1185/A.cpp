#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
int main()
{
    int a[3], d;
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &d);
    sort(a, a + 3);
    printf("%d\n", max(d - (a[1] - a[0]), 0) + max(d - (a[2] - a[1]), 0));
    return 0;
}