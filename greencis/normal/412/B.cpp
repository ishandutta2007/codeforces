#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;

int n,a[999],k;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    printf("%d",a[k-1]);

    return 0;
}