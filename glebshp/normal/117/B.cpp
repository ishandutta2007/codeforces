#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int inf = 1000 * 1000 * 1000;

int main()
{
    int a, b, mod, i, ost;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &a, &b, &mod);
    ost = 0;
    for (i = 1; i <= min(a, mod); i++)
    {
        ost += inf;
        ost %= mod;
        if (ost == 0 || ost + b >= mod)
            continue;
        printf("1 %.9d\n", i);
        return 0;
    }
    printf("2\n");

    return 0;
}