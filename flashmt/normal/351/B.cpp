#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int tree[3333], n;

void add(int x)
{
    for (int i = x; i <= n; i += i & -i) tree[i]++;
}

int get(int x)
{
    int res = 0;
    for (int i = x; i; i -= i & -i) res += tree[i];
    return res;
}

int main()
{
    int inversion = 0, x;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x;
        inversion += i - 1 - get(x);
        add(x);
    }
        
    printf("%d\n", inversion * 2 - inversion % 2);
}