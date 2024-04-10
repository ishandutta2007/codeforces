#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int run = 1; run <= test; run++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", (n%2)? 0:1);
    }
}